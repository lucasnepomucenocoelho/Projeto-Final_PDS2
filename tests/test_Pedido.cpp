#include "doctest.h"
#include "Pedido.hpp"
#include "Jogo.hpp"
#include <memory>
#include <vector>

TEST_CASE("Pedido - calcularTotal soma itens corretamente") {
    auto jogo = std::make_shared<Jogo>("Persona 5 Royal", "PS5", 249.90,
                                        Condicao::NOVO, 3, "RPG", "16");
    std::vector<ItemCompra> itens = { {jogo, 2} };
    Pagamento pagamento(499.80, FormaPagamento::PIX);

    Pedido pedido(itens, "Rua D, 100", pagamento);

    CHECK(pedido.calcularTotal() == doctest::Approx(499.80));
}

TEST_CASE("Pedido - status inicial pendente") {
    auto jogo = std::make_shared<Jogo>("Hades", "PC", 69.90,
                                        Condicao::NOVO, 1, "Roguelike", "16");
    std::vector<ItemCompra> itens = { {jogo, 1} };
    Pagamento pagamento(69.90, FormaPagamento::CARTAO);

    Pedido pedido(itens, "Rua E, 200", pagamento);

    CHECK(pedido.getStatus() == StatusPedido::PENDENTE);
}

TEST_CASE("Pedido - cancelar enquanto pendente") {
    auto jogo = std::make_shared<Jogo>("Stardew Valley", "Switch", 39.90,
                                        Condicao::NOVO, 1, "Simulacao", "L");
    std::vector<ItemCompra> itens = { {jogo, 1} };
    Pagamento pagamento(39.90, FormaPagamento::BOLETO);

    Pedido pedido(itens, "Rua F, 300", pagamento);

    CHECK(pedido.cancelar() == true);
    CHECK(pedido.getStatus() == StatusPedido::CANCELADO);
}

TEST_CASE("Pedido - cancelar apos enviado falha") {
    auto jogo = std::make_shared<Jogo>("Cuphead", "Xbox", 59.90,
                                        Condicao::NOVO, 1, "Plataforma", "10");
    std::vector<ItemCompra> itens = { {jogo, 1} };
    Pagamento pagamento(59.90, FormaPagamento::CARTAO);

    Pedido pedido(itens, "Rua G, 400", pagamento);
    pedido.atualizarStatus(StatusPedido::ENVIADO);

    CHECK(pedido.cancelar() == false);
}
