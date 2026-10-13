#include "doctest.h"

#include "Pagamento.hpp"

TEST_CASE("Pagamento: construtor inicializa valor, forma e status PENDENTE") {
    Pagamento p(150.0, FormaPagamento::PIX);

    CHECK(p.getValor() == doctest::Approx(150.0));
    CHECK(p.getForma() == FormaPagamento::PIX);
    CHECK(p.getStatus() == StatusPagamento::PENDENTE);
}

TEST_CASE("Pagamento: construtor aceita todas as formas de pagamento") {
    Pagamento cartao(100.0, FormaPagamento::CARTAO);
    Pagamento boleto(100.0, FormaPagamento::BOLETO);
    Pagamento pix(100.0, FormaPagamento::PIX);

    CHECK(cartao.getForma() == FormaPagamento::CARTAO);
    CHECK(boleto.getForma() == FormaPagamento::BOLETO);
    CHECK(pix.getForma() == FormaPagamento::PIX);
}

TEST_CASE("Pagamento: processar retorna true e aprova pagamento válido") {
    Pagamento p(200.0, FormaPagamento::CARTAO);

    CHECK(p.processar() == true);
    CHECK(p.getStatus() == StatusPagamento::APROVADO);
}

TEST_CASE("Pagamento: processar recusa valor inválido (<= 0)") {
    Pagamento p(0.0, FormaPagamento::PIX);

    CHECK(p.processar() == false);
    CHECK(p.getStatus() == StatusPagamento::RECUSADO);
}

TEST_CASE("Pagamento: processar recusa valor negativo") {
    Pagamento p(-10.0, FormaPagamento::BOLETO);

    CHECK(p.processar() == false);
    CHECK(p.getStatus() == StatusPagamento::RECUSADO);
}

TEST_CASE("Pagamento: status permanece PENDENTE antes de processar") {
    Pagamento p(50.0, FormaPagamento::PIX);

    CHECK(p.getStatus() == StatusPagamento::PENDENTE);
    CHECK(p.getStatus() == StatusPagamento::PENDENTE);
}

TEST_CASE("Pagamento: valores com casas decimais são mantidos") {
    Pagamento p(99.99, FormaPagamento::CARTAO);

    CHECK(p.getValor() == doctest::Approx(99.99));
}