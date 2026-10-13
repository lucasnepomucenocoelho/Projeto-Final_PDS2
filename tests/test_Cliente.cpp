#include "doctest.h"
#include "Cliente.hpp"

TEST_CASE("Cliente - autenticar com credenciais corretas") {
    Cliente c("Pedro", "pedro@email.com", "senha123", "Rua A, 1");
    CHECK(c.autenticar("pedro@email.com", "senha123") == true);
}

TEST_CASE("Cliente - autenticar com credenciais erradas") {
    Cliente c("Pedro", "pedro@email.com", "senha123", "Rua A, 1");
    CHECK(c.autenticar("pedro@email.com", "errada") == false);
    CHECK(c.autenticar("outro@email.com", "senha123") == false);
    CHECK(c.autenticar("", "") == false);
}

TEST_CASE("Cliente - editar perfil") {
    Cliente c("Pedro", "pedro@email.com", "senha123", "Rua A, 1");
    c.editarPerfil("Pedro Silva", "pedro.novo@email.com", "Rua B, 2");
    CHECK(c.getNome() == "Pedro Silva");
    CHECK(c.getEmail() == "pedro.novo@email.com");
}

TEST_CASE("Cliente - criar solicitacao de venda") {
    Cliente c("Pedro", "pedro@email.com", "senha123", "Rua A, 1");
    auto s = c.criarSolicitacaoVenda("PS4 usado", 800.0);
    CHECK(s.getClienteId() == "pedro@email.com");
    CHECK(c.getSolicitacoesVenda().size() == 1);
}

TEST_CASE("Cliente - carrinho comeca vazio") {
    Cliente c("Pedro", "pedro@email.com", "senha123", "Rua A, 1");
    CHECK(c.getCarrinho().getItens().empty());
}
