#include "doctest.h"

#include "CarrinhoDeCompras.hpp"
#include "ItemCarrinho.hpp"
#include "Produto.hpp"

#include <memory>

static std::shared_ptr<Produto> criarProduto(const std::string& nome,
                                             double preco,
                                             int estoque)
{
    auto p = std::make_shared<Produto>();
    p->setNome(nome);
    p->setPreco(preco);
    p->setEstoque(estoque);
    return p;
}

TEST_CASE("CarrinhoDeCompras: começa vazio") {
    CarrinhoDeCompras carrinho;
    CHECK(carrinho.getItens().empty());
    CHECK(carrinho.calcularTotal() == doctest::Approx(0.0));
}

TEST_CASE("CarrinhoDeCompras: adicionar item válido retorna true") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Camiseta", 49.90, 10);

    CHECK(carrinho.adicionarItem(produto, 2) == true);
    CHECK(carrinho.getItens().size() == 1);
}

TEST_CASE("CarrinhoDeCompras: não adiciona sem estoque suficiente") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Tênis", 299.90, 1);

    CHECK(carrinho.adicionarItem(produto, 5) == false);
    CHECK(carrinho.getItens().empty());
}

TEST_CASE("CarrinhoDeCompras: adicionar o mesmo produto acumula quantidade") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Caneca", 19.90, 10);

    CHECK(carrinho.adicionarItem(produto, 1) == true);
    CHECK(carrinho.adicionarItem(produto, 2) == true);

    REQUIRE(carrinho.getItens().size() == 1);
    CHECK(carrinho.getItens()[0].getQuantidade() == 3);
}

TEST_CASE("CarrinhoDeCompras: calcularTotal soma corretamente") {
    CarrinhoDeCompras carrinho;
    auto p1 = criarProduto("Livro", 50.0, 10);
    auto p2 = criarProduto("Caneta", 5.0, 100);

    carrinho.adicionarItem(p1, 2); // 100
    carrinho.adicionarItem(p2, 4); // 20

    CHECK(carrinho.calcularTotal() == doctest::Approx(120.0));
}

TEST_CASE("CarrinhoDeCompras: remover produto existente") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Fone", 89.90, 5);

    carrinho.adicionarItem(produto, 1);
    REQUIRE(carrinho.getItens().size() == 1);

    carrinho.removerproduto(produto);
    CHECK(carrinho.getItens().empty());
}

TEST_CASE("CarrinhoDeCompras: remover produto inexistente não altera o carrinho") {
    CarrinhoDeCompras carrinho;
    auto p1 = criarProduto("A", 10.0, 5);
    auto p2 = criarProduto("B", 20.0, 5);

    carrinho.adicionarItem(p1, 1);
    carrinho.removerproduto(p2);

    CHECK(carrinho.getItens().size() == 1);
}

TEST_CASE("CarrinhoDeCompras: atualizar quantidade de item existente") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Mouse", 120.0, 10);

    carrinho.adicionarItem(produto, 1);
    carrinho.atualizarQuantidade(produto, 4);

    REQUIRE(carrinho.getItens().size() == 1);
    CHECK(carrinho.getItens()[0].getQuantidade() == 4);
    CHECK(carrinho.calcularTotal() == doctest::Approx(480.0));
}

TEST_CASE("CarrinhoDeCompras: atualizar quantidade para <= 0 remove o item") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Teclado", 200.0, 5);

    carrinho.adicionarItem(produto, 2);
    carrinho.atualizarQuantidade(produto, 0);

    CHECK(carrinho.getItens().empty());
}

TEST_CASE("CarrinhoDeCompras: esvaziar limpa todos os itens") {
    CarrinhoDeCompras carrinho;
    auto p1 = criarProduto("P1", 10.0, 10);
    auto p2 = criarProduto("P2", 20.0, 10);

    carrinho.adicionarItem(p1, 1);
    carrinho.adicionarItem(p2, 1);

    carrinho.esvaziar();

    CHECK(carrinho.getItens().empty());
    CHECK(carrinho.calcularTotal() == doctest::Approx(0.0));
}

TEST_CASE("CarrinhoDeCompras: adicionar produto nulo é rejeitado") {
    CarrinhoDeCompras carrinho;

    CHECK(carrinho.adicionarItem(nullptr, 1) == false);
    CHECK(carrinho.getItens().empty());
}

TEST_CASE("CarrinhoDeCompras: adicionar quantidade inválida é rejeitado") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("X", 10.0, 10);

    CHECK(carrinho.adicionarItem(produto, 0) == false);
    CHECK(carrinho.adicionarItem(produto, -3) == false);
    CHECK(carrinho.getItens().empty());
}