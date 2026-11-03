#include "Jogo.hpp"
#include <sstream>
#include <stdexcept>

Jogo::Jogo(const std::string& titulo, const std::string& plataforma,
           double preco, Condicao condicao, int quantidadeEstoque,
           const std::string& genero, const std::string& classificacaoIndicativa)
    : Produto(titulo, plataforma, preco, condicao, quantidadeEstoque),
      genero_(genero), classificacaoIndicativa_(classificacaoIndicativa) {
    if (genero.empty()) throw std::invalid_argument("O genero nao pode ser vazio");
    if (classificacaoIndicativa.empty()) throw std::invalid_argument("A classificacao nao pode ser vazia");
}

std::string Jogo::getCategoria() const { return "Jogo"; }

std::string Jogo::getDescricaoDetalhada() const {
    std::ostringstream oss;
    oss << "Jogo: " << titulo_
        << " | Plataforma: " << plataforma_
        << " | Genero: " << genero_
        << " | Classificacao: " << classificacaoIndicativa_
        << " | Preco: R$ " << preco_
        << " | Condicao: " << (condicao_ == Condicao::NOVO ? "Novo" : "Usado")
        << " | Estoque: " << quantidadeEstoque_;
    return oss.str();
}

std::string Jogo::getGenero() const { return genero_; }
