#include "doctest.h"
#include "Persistencia.hpp"
#include "Estoque.hpp"
#include "Jogo.hpp"
#include <cstdio>
#include <stdexcept>
TEST_CASE("Persistencia - salvar e carregar catalogo") {
    Estoque e1;
    e1.adicionarProduto(std::make_shared<Jogo>("Elden Ring", "PS5", 250.0, Condicao::NOVO, 10, "RPG", "16"));
    
    // Salva no arquivo temporario
    Persistencia::salvar(e1, "teste_catalogo.txt");
    
    // Carrega em um estoque vazio
    Estoque e2;
    Persistencia::carregar(e2, "teste_catalogo.txt");
    
    REQUIRE(e2.listarProdutos().size() == 1);
    CHECK(e2.listarProdutos()[0]->getTitulo() == "Elden Ring");
    CHECK(e2.listarProdutos()[0]->getPreco() == doctest::Approx(250.0));
    
    // Remove o arquivo temporario
    std::remove("teste_catalogo.txt");
}

TEST_CASE("Persistencia - carregar arquivo inexistente nao quebra") {
    Estoque e;
    Persistencia::carregar(e, "arquivo_que_nao_existe.txt");
    CHECK(e.listarProdutos().empty());
}
TEST_CASE("Persistencia - lanca excecao ao tentar salvar em diretorio invalido") {
    Estoque e;
    e.adicionarProduto(std::make_shared<Jogo>("Teste", "PC", 10.0, Condicao::NOVO, 1, "Acao", "L"));
    
    // Tenta salvar em um caminho que nao existe (diretorio invalido)
    CHECK_THROWS_AS(Persistencia::salvar(e, "diretorio_inexistente/arquivo.txt"), std::runtime_error);
}
