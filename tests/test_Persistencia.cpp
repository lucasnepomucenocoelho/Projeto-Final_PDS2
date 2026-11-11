#include "doctest.h"
#include "Persistencia.hpp"
#include "Estoque.hpp"
#include "Jogo.hpp"
#include <cstdio>

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