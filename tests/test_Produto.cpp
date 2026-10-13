#include "doctest.h"
#include "Jogo.hpp"
#include "Console.hpp"
#include "Acessorio.hpp"
#include <memory>
#include <vector>

// Produto é abstrata: os testes usam as subclasses concretas
// (Jogo, Console, Acessorio) para validar o comportamento herdado.

TEST_CASE("Produto - construtor guarda os dados informados") {
    Jogo jogo("The Legend of Zelda", "Switch", 299.90, Condicao::NOVO, 5,
              "Aventura", "L");

    CHECK(jogo.getTitulo() == "The Legend of Zelda");
    CHECK(jogo.getPlataforma() == "Switch");
    CHECK(jogo.getPreco() == doctest::Approx(299.90));
    CHECK(jogo.getCondicao() == Condicao::NOVO);
    CHECK(jogo.getQuantidadeEstoque() == 5);
}

TEST_CASE("Produto - verificarDisponibilidade") {
    Jogo jogo("Zelda", "Switch", 299.90, Condicao::NOVO, 5, "Aventura", "L");

    CHECK(jogo.verificarDisponibilidade(3) == true);
    CHECK(jogo.verificarDisponibilidade(5) == true);   // exatamente o estoque
    CHECK(jogo.verificarDisponibilidade(6) == false);  // acima do estoque
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
    Jogo jogo("Hollow Knight", "Switch", 59.90, Condicao::USADO, 1,
              "Metroidvania", "10");
    CHECK(jogo.getCondicao() == Condicao::USADO);

    jogo.setQuantidadeEstoque(0);
    CHECK(jogo.estaEsgotado() == true);
}

TEST_CASE("Produto - polimorfismo: cada subclasse informa sua categoria") {
    std::vector<std::shared_ptr<Produto>> produtos;
    produtos.push_back(std::make_shared<Jogo>("Hades", "PC", 69.90,
                        Condicao::NOVO, 3, "Roguelike", "16"));
    produtos.push_back(std::make_shared<Console>("PlayStation 5", "PS5", 3999.90,
                        Condicao::NOVO, 2, 825, true));
    produtos.push_back(std::make_shared<Acessorio>("DualSense", "PS5", 499.90,
                        Condicao::NOVO, 10, "Controle", "PS5"));

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
    Jogo jogo("Hollow Knight", "Switch", 59.90, Condicao::USADO, 1,
              "Metroidvania", "10");
    CHECK(jogo.getGenero() == "Metroidvania");
}
