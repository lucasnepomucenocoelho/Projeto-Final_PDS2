#include "doctest.h"
#include "Pagamento.hpp"

TEST_CASE("Pagamento - fluxos validos") {
    Pagamento p1(100.0, FormaPagamento::PIX);
    CHECK(p1.processar() == true);
    
    Pagamento p2(100.0, FormaPagamento::CARTAO);
    CHECK(p2.processar() == true);
}

TEST_CASE("Pagamento - boleto e valores invalidos") {
    Pagamento p1(100.0, FormaPagamento::BOLETO);
    CHECK(p1.processar() == false); // Cobre linha 16-18
    
    Pagamento p2(0.0, FormaPagamento::PIX);
    CHECK(p2.processar() == false); // Cobre linha 20
}
