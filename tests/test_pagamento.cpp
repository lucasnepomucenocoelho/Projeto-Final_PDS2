#include "doctest.h"
#include "Pagamento.hpp"
#include <stdexcept>

TEST_CASE("Pagamento - fluxos validos") {
    Pagamento p1(100.0, FormaPagamento::PIX);
    CHECK(p1.processar() == true);
    
    Pagamento p2(100.0, FormaPagamento::CARTAO);
    CHECK(p2.processar() == true);
}

TEST_CASE("Pagamento - boleto fica pendente") {
    Pagamento p1(100.0, FormaPagamento::BOLETO);
    CHECK(p1.processar() == false); 
}

TEST_CASE("Pagamento - lanca excecao para valor invalido") {
    CHECK_THROWS_AS(Pagamento(0.0, FormaPagamento::PIX), std::invalid_argument);
    CHECK_THROWS_AS(Pagamento(-50.0, FormaPagamento::PIX), std::invalid_argument);
}
