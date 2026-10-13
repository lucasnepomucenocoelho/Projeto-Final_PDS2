#include "doctest.h"
#include "SolicitacaoVenda.hpp"

TEST_CASE("SolicitacaoVenda - status inicial em analise") {
    SolicitacaoVenda solicitacao("cliente@email.com",
                                  "Jogo usado - God of War - PS4 - bom estado", 80.00);

    CHECK(solicitacao.getStatus() == StatusSolicitacao::EM_ANALISE);
}

TEST_CASE("SolicitacaoVenda - aprovar define precoFinal, status e gera Produto") {
    SolicitacaoVenda solicitacao("cliente@email.com",
                                  "Console usado - Xbox One - funcionando", 900.00);

    auto produto = solicitacao.aprovar(850.00);

    CHECK(solicitacao.getStatus() == StatusSolicitacao::APROVADA);
    CHECK(solicitacao.getPrecoFinal() == doctest::Approx(850.00));
    CHECK(static_cast<bool>(produto));
}

TEST_CASE("SolicitacaoVenda - recusar define status") {
    SolicitacaoVenda solicitacao("cliente@email.com", "Acessorio danificado", 50.00);

    solicitacao.recusar("Produto em mau estado de conservacao");

    CHECK(solicitacao.getStatus() == StatusSolicitacao::RECUSADA);
}
