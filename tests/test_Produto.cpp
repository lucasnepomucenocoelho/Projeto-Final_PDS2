#include "doctest.h"
#include "Jogo.hpp"
#include "Console.hpp"
#include "Acessorio.hpp"
#include <memory>
#include <vector>
#include <stdexcept>

TEST_CASE("Produto - construtor guarda os dados informados") {
    Jogo jogo("The Legend of Zelda", "Switch", 299.90, Condicao::NOVO, 5, "Aventura", "L");
    CHECK(jogo.getTitulo() == "The Legend of Zelda");
    CHECK(jogo.getPlataforma() == "Switch");
    CHECK(jogo.getPreco() == doctest::Approx(299.90));
    CHECK(jogo.getCondicao() == Condicao::NOVO);
    CHECK(jogo.getQuantidadeEstoque() == 5);
}

TEST_CASE("Produto - verificarDisponibilidade") {
    Jogo jogo("Zelda", "Switch", 299.90, Condicao::NOVO, 5, "Aventura", "L");
    CHECK(jogo.verificarDisponibilidade(3) == true);
    CHECK(jogo.verificarDisponibilidade(5) == true);
    CHECK(jogo.verificarDisponibilidade(6) == false);
}

TEST_CASE("Produto - estaEsgotado") {
    Jogo esgotado("FIFA 26", "PS5", 349.90, Condicao::NOVO, 0, "Esporte", "L");
    Jogo disponivel("FIFA 26", "PS5", 349.90, Condicao::NOVO, 2, "Esporte", "L");
    CHECK(esgotado.estaEsgotado() == true);
    CHECK(disponivel.estaEsgotado() == false);
}

TEST_CASE("Produto - atualizarPreco") {
    Jogo jogo("Elden Ring", "PC", 199.90, Condicao::NOVO, 10, "RPG", "16");
    jogo.atualizarPreco(149.90);
    CHECK(jogo.getPreco() == doctest::Approx(149.90));
}

TEST_CASE("Produto - setQuantidadeEstoque atualiza a quantidade") {
    Jogo jogo("Celeste", "Switch", 49.90, Condicao::USADO, 1, "Plataforma", "L");
    jogo.setQuantidadeEstoque(7);
    CHECK(jogo.getQuantidadeEstoque() == 7);
}

TEST_CASE("Produto - condicao USADO e produto esgotado apos zerar estoque") {
    Jogo jogo("Hollow Knight", "Switch", 59.90, Condicao::USADO, 1, "Metroidvania", "10");
    CHECK(jogo.getCondicao() == Condicao::USADO);
    jogo.setQuantidadeEstoque(0);
    CHECK(jogo.estaEsgotado() == true);
}

TEST_CASE("Produto - polimorfismo: cada subclasse informa sua categoria") {
    std::vector<std::shared_ptr<Produto>> produtos;
    produtos.push_back(std::make_shared<Jogo>("Hades", "PC", 69.90, Condicao::NOVO, 3, "Roguelike", "16"));
    produtos.push_back(std::make_shared<Console>("PlayStation 5", "PS5", 3999.90, Condicao::NOVO, 2, 825, true));
    produtos.push_back(std::make_shared<Acessorio>("DualSense", "PS5", 499.90, Condicao::NOVO, 10, "Controle", "PS5"));

    CHECK(produtos[0]->getCategoria() == "Jogo");
    CHECK(produtos[1]->getCategoria() == "Console");
    CHECK(produtos[2]->getCategoria() == "Acessorio");
}

TEST_CASE("Produto - getDescricaoDetalhada inclui o titulo do produto") {
    Jogo jogo("Persona 5 Royal", "PS5", 249.90, Condicao::NOVO, 3, "RPG", "16");
    std::string descricao = jogo.getDescricaoDetalhada();
    CHECK(descricao.find("Persona 5 Royal") != std::string::npos);
}

TEST_CASE("Jogo - getGenero") {
    Jogo jogo("Hollow Knight", "Switch", 59.90, Condicao::USADO, 1, "Metroidvania", "10");
    CHECK(jogo.getGenero() == "Metroidvania");
}

// --- TESTES DE EXCEÇÃO DO C09 ---
TEST_CASE("Produto - lanca excecao para titulo ou plataforma vazios") {
    CHECK_THROWS_AS(Jogo("", "PS5", 100.0, Condicao::NOVO, 1, "RPG", "L"), std::invalid_argument);
    CHECK_THROWS_AS(Jogo("Elden", "", 100.0, Condicao::NOVO, 1, "RPG", "L"), std::invalid_argument);
}

TEST_CASE("Produto - lanca excecao para preco negativo") {
    CHECK_THROWS_AS(Jogo("Bug", "PC", -50.0, Condicao::NOVO, 1, "Acao", "L"), std::invalid_argument);
}

TEST_CASE("Produto - lanca excecao para estoque negativo") {
    CHECK_THROWS_AS(Jogo("Bug", "PC", 50.0, Condicao::NOVO, -1, "Acao", "L"), std::invalid_argument);
}

TEST_CASE("Subclasses - lancam excecao para atributos invalidos") {
    CHECK_THROWS_AS(Jogo("Elden", "PS5", 100.0, Condicao::NOVO, 1, "", "L"), std::invalid_argument);
    CHECK_THROWS_AS(Console("PS5", "PS5", 4000.0, Condicao::NOVO, 1, -10, true), std::invalid_argument);
    CHECK_THROWS_AS(Acessorio("DualSense", "PS5", 400.0, Condicao::NOVO, 1, "", "PS5"), std::invalid_argument);
}
