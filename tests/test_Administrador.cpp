#include "doctest.h"
#include "Administrador.hpp"
#include "Estoque.hpp"
#include "SolicitacaoVenda.hpp"
#include "Pedido.hpp"
#include "Jogo.hpp"
#include <memory>
#include <vector>

TEST_CASE("Administrador - autenticar com credenciais corretas") {
    Administrador admin("Carlos Souza", "admin@loja.com", "admin123");
    CHECK(admin.autenticar("admin@loja.com", "admin123") == true);
}

TEST_CASE("Administrador - autenticar com senha incorreta") {
    Administrador admin("Carlos Souza", "admin@loja.com", "admin123");
    CHECK(admin.autenticar("admin@loja.com", "errada") == false);
}

TEST_CASE("Administrador - autenticar com email incorreto") {
    Administrador admin("Carlos Souza", "admin@loja.com", "admin123");
    CHECK(admin.autenticar("outro@loja.com", "admin123") == false);
}

TEST_CASE("Administrador - cadastrarProduto adiciona ao estoque") {
    Administrador admin("Carlos Souza", "admin@loja.com", "admin123");
    Estoque estoque;
    auto jogo = std::make_shared<Jogo>("Sekiro", "PS5", 199.90,
                                        Condicao::NOVO, 5, "Acao", "16");

    admin.cadastrarProduto(jogo, estoque);

    CHECK(estoque.listarProdutos().size() == 1);
}

TEST_CASE("Administrador - removerProduto cadastrado") {
    Administrador admin("Carlos Souza", "admin@loja.com", "admin123");
    Estoque estoque;
    auto jogo = std::make_shared<Jogo>("Sekiro", "PS5", 199.90,
                                        Condicao::NOVO, 5, "Acao", "16");
    admin.cadastrarProduto(jogo, estoque);

    CHECK(admin.removerProduto(jogo, estoque) == true);
    CHECK(estoque.listarProdutos().empty());
}

TEST_CASE("Administrador - avaliarSolicitacao aprovando adiciona produto ao estoque") {
    Administrador admin("Carlos Souza", "admin@loja.com", "admin123");
    Estoque estoque;
    SolicitacaoVenda solicitacao("cliente@email.com",
                                  "Jogo usado - Dark Souls 3 - PC", 70.00);

    admin.avaliarSolicitacao(solicitacao, true, 65.00, estoque);

    CHECK(solicitacao.getStatus() == StatusSolicitacao::APROVADA);
    CHECK(solicitacao.getPrecoFinal() == doctest::Approx(65.00));
    CHECK(estoque.listarProdutos().size() == 1);
}

TEST_CASE("Administrador - avaliarSolicitacao recusando nao altera o estoque") {
    Administrador admin("Carlos Souza", "admin@loja.com", "admin123");
    Estoque estoque;
    SolicitacaoVenda solicitacao("cliente@email.com",
                                  "Acessorio danificado", 50.00);

    admin.avaliarSolicitacao(solicitacao, false, 0.0, estoque);

    CHECK(solicitacao.getStatus() == StatusSolicitacao::RECUSADA);
    CHECK(estoque.listarProdutos().empty());
}

TEST_CASE("Administrador - gerarRelatorioVendas retorna conteudo") {
    Administrador admin("Carlos Souza", "admin@loja.com", "admin123");
    auto jogo = std::make_shared<Jogo>("Hades", "PC", 69.90,
                                        Condicao::NOVO, 3, "Roguelike", "16");
    std::vector<ItemCompra> itens = { {jogo, 2} };
    Pagamento pagamento(139.80, FormaPagamento::PIX);
    std::vector<Pedido> pedidos = { Pedido(itens, "Rua A, 100", pagamento) };

    std::string relatorio = admin.gerarRelatorioVendas(pedidos);

    CHECK(!relatorio.empty());
}
