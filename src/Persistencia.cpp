#include "Persistencia.hpp"
#include "Jogo.hpp"
#include "Console.hpp"
#include "Acessorio.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

/**
 * @brief Salva o estado atual do estoque em um arquivo de texto.
 * O formato utilizado é separado por ponto e vírgula (;).
 * @param estoque O objeto Estoque com os produtos a serem salvos.
 * @param nomeArquivo O caminho do arquivo onde os dados serão escritos.
 * @throws std::runtime_error se não for possível abrir o arquivo.
 */
void Persistencia::salvar(const Estoque& estoque, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir o arquivo para salvar.");
    }
    
    for (const auto& prod : estoque.listarProdutos()) {
        arquivo << prod->getCategoria() << ";" 
                << prod->getTitulo() << ";"
                << prod->getPlataforma() << ";"
                << prod->getPreco() << ";"
                << prod->getQuantidadeEstoque() << "\n";
    }
    arquivo.close();
}

/**
 * @brief Carrega os dados de um arquivo de texto e popula o Estoque.
 * Lê linha por linha, separa os campos e instancia a subclasse correta
 * (Jogo, Console ou Acessorio) com base na categoria.
 * @param estoque Referência ao Estoque que será populado.
 * @param nomeArquivo O caminho do arquivo a ser lido.
 */
void Persistencia::carregar(Estoque& estoque, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        return; // Se o arquivo nao existe, ignora silenciosamente.
    }
    
    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string categoria, titulo, plataforma;
        double preco;
        int qtd;

        std::getline(ss, categoria, ';');
        std::getline(ss, titulo, ';');
        std::getline(ss, plataforma, ';');
        ss >> preco;
        ss.ignore();
        ss >> qtd;

        try {
            if (categoria == "Jogo") {
                estoque.adicionarProduto(std::make_shared<Jogo>(titulo, plataforma, preco, Condicao::NOVO, qtd, "Indefinido", "L"));
            } else if (categoria == "Console") {
                estoque.adicionarProduto(std::make_shared<Console>(titulo, plataforma, preco, Condicao::NOVO, qtd, 500, true));
            } else if (categoria == "Acessorio") {
                estoque.adicionarProduto(std::make_shared<Acessorio>(titulo, plataforma, preco, Condicao::NOVO, qtd, "Geral", plataforma));
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro ao carregar produto: " << e.what() << "\n";
        }
    }
}
