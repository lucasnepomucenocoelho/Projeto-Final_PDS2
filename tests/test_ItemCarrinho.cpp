#include "doctest.h"
#include "ItemCarrinho.hpp"
#include "Jogo.hpp"

TEST_CASE("ItemCompra - subtotal com quantidade 1") {
    auto jogo = std::make_shared<Jogo>(
        "Elden Ring", "PS5", 250.0, Condicao::NOVO, 10, "RPG", "16");
    ItemCompra item{jogo, 1};
    CHECK(item.subtotal() == doctest::Approx(250.0));
}

TEST_CASE("ItemCompra - subtotal com quantidade 3") {
    auto jogo = std::make_shared<Jogo>(
        "Mario", "Switch", 300.0, Condicao::NOVO, 5, "Plataforma", "L");
    ItemCompra item{jogo, 3};
    CHECK(item.subtotal() == doctest::Approx(900.0));
}

TEST_CASE("ItemCompra - subtotal com produto nulo") {
    ItemCompra item{nullptr, 5};
    CHECK(item.subtotal() == doctest::Approx(0.0));
}

TEST_CASE("ItemCompra - subtotal com quantidade zero") {
    auto jogo = std::make_shared<Jogo>(
        "Zelda", "Switch", 350.0, Condicao::NOVO, 5, "Aventura", "L");
    ItemCompra item{jogo, 0};
    CHECK(item.subtotal() == doctest::Approx(0.0));
}
