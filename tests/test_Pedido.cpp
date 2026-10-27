#include "doctest.h"
#include "Pedido.hpp"
#include "Jogo.hpp"

TEST_CASE("Pedido - fluxo normal") {
    auto jogo = std::make_shared<Jogo>("Mario", "Switch", 100.0, Condicao::NOVO, 5, "Aventura", "L");
    std::vector<ItemCompra> itens = {{jogo, 1}};
    Pagamento pg(100.0, FormaPagamento::PIX);
    
    Pedido p1(itens, "Rua 1", pg);
    CHECK(p1.calcularTotal() == doctest::Approx(100.0));
    CHECK(p1.processarPagamento() == true);
    CHECK(p1.cancelar() == true);
}

TEST_CASE("Pedido - caminhos de erro (ja pago/ja cancelado)") {
    auto jogo = std::make_shared<Jogo>("Mario", "Switch", 100.0, Condicao::NOVO, 5, "Aventura", "L");
    std::vector<ItemCompra> itens = {{jogo, 1}};
    Pagamento pg(100.0, FormaPagamento::PIX);
    
    Pedido p1(itens, "Rua 1", pg);
    p1.atualizarStatus(StatusPedido::ENTREGUE);
    CHECK(p1.processarPagamento() == false); // Cobre linha 30

    Pedido p2(itens, "Rua 2", pg);
    p2.atualizarStatus(StatusPedido::CANCELADO);
    CHECK(p2.cancelar() == false); // Cobre linha 49
}
