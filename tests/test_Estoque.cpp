#include "doctest.h"
#include "Estoque.hpp"
#include "Jogo.hpp"
#include "Console.hpp"
#include <memory>

TEST_CASE("Estoque - inicia vazio") {
    Estoque estoque;
    CHECK(estoque.listarProdutos().empty());
}

TEST_CASE("Estoque - adicionarProduto e listarProdutos") {
    Estoque estoque;
    auto jogo = std::make_shared<Jogo>("Hollow Knight", "Switch", 59.90,
                                        Condicao::USADO, 3, "Metroidvania", "10");

    estoque.adicionarProduto(jogo);

    CHECK(estoque.listarProdutos().size() == 1);
}

TEST_CASE("Estoque - adicionarProduto varios produtos de tipos diferentes") {
    Estoque estoque;
    estoque.adicionarProduto(std::make_shared<Jogo>("Hades", "PC", 69.90,
                              Condicao::NOVO, 2, "Roguelike", "16"));
    estoque.adicionarProduto(std::make_shared<Console>("Xbox Series X", "Xbox",
                              4299.90, Condicao::NOVO, 1, 1000, true));

    CHECK(estoque.listarProdutos().size() == 2);
}

TEST_CASE("Estoque - verificarDisponibilidade") {
    Estoque estoque;
    auto jogo = std::make_shared<Jogo>("Rayman Legends", "PS5", 89.90,
                                        Condicao::NOVO, 5, "Plataforma", "L");
    estoque.adicionarProduto(jogo);

    CHECK(estoque.verificarDisponibilidade(jogo, 3) == true);
    CHECK(estoque.verificarDisponibilidade(jogo, 5) == true);
    CHECK(estoque.verificarDisponibilidade(jogo, 6) == false);
}

TEST_CASE("Estoque - darBaixa reduz a quantidade do produto") {
    Estoque estoque;
    auto jogo = std::make_shared<Jogo>("Rayman Legends", "PS5", 89.90,
                                        Condicao::NOVO, 5, "Plataforma", "L");
    estoque.adicionarProduto(jogo);

    estoque.darBaixa(jogo, 3);

    CHECK(jogo->getQuantidadeEstoque() == 2);
}

TEST_CASE("Estoque - darBaixa de todo o estoque esgota o produto") {
    Estoque estoque;
    auto jogo = std::make_shared<Jogo>("Cuphead", "Xbox", 59.90,
                                        Condicao::NOVO, 2, "Plataforma", "10");
    estoque.adicionarProduto(jogo);

    estoque.darBaixa(jogo, 2);

    CHECK(jogo->estaEsgotado() == true);
}

TEST_CASE("Estoque - reporQuantidade") {
    Estoque estoque;
    auto jogo = std::make_shared<Jogo>("Portal 2", "PC", 29.90,
                                        Condicao::NOVO, 0, "Puzzle", "L");
    estoque.adicionarProduto(jogo);

    estoque.reporQuantidade(jogo, 10);

    CHECK(jogo->getQuantidadeEstoque() == 10);
}

TEST_CASE("Estoque - removerProduto existente") {
    Estoque estoque;
    auto jogo = std::make_shared<Jogo>("Sekiro", "PS5", 199.90,
                                        Condicao::NOVO, 1, "Acao", "16");
    estoque.adicionarProduto(jogo);

    CHECK(estoque.removerProduto(jogo) == true);
    CHECK(estoque.listarProdutos().empty());
}

TEST_CASE("Estoque - removerProduto inexistente retorna false") {
    Estoque estoque;
    auto jogo = std::make_shared<Jogo>("Sekiro", "PS5", 199.90,
                                        Condicao::NOVO, 1, "Acao", "16");

    CHECK(estoque.removerProduto(jogo) == false);
}
