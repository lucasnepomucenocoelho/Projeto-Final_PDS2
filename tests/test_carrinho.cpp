#include "doctest.h"

#include "CarrinhoDeCompras.hpp"
#include "ItemCarrinho.hpp"
#include "Jogo.hpp"

#include <memory>

static std::shared_ptr<Produto> criarProduto(const std::string& nome,
                                             double preco,
                                             int estoque)
{
    return std::make_shared<Jogo>(nome, "PS5", preco,
                                   Condicao::NOVO, estoque, "RPG", "L");
}

TEST_CASE("CarrinhoDeCompras: comeca vazio") {
    CarrinhoDeCompras carrinho;
    CHECK(carrinho.getItens().empty());
    CHECK(carrinho.calcularTotal() == doctest::Approx(0.0));
}

TEST_CASE("CarrinhoDeCompras: adicionar item valido retorna true") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Elden Ring", 250.0, 10);

    CHECK(carrinho.adicionarItem(produto, 2) == true);
    CHECK(carrinho.getItens().size() == 1);
}

TEST_CASE("CarrinhoDeCompras: nao adiciona sem estoque suficiente") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Zelda", 350.0, 1);

    CHECK(carrinho.adicionarItem(produto, 5) == false);
    CHECK(carrinho.getItens().empty());
}

TEST_CASE("CarrinhoDeCompras: adicionar o mesmo produto acumula quantidade") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Mario", 300.0, 10);

    CHECK(carrinho.adicionarItem(produto, 1) == true);
    CHECK(carrinho.adicionarItem(produto, 2) == true);

    REQUIRE(carrinho.getItens().size() == 1);
    CHECK(carrinho.getItens()[0].quantidade == 3);
}

TEST_CASE("CarrinhoDeCompras: calcularTotal soma corretamente") {
    CarrinhoDeCompras carrinho;
    auto p1 = criarProduto("Elden Ring", 50.0, 10);
    auto p2 = criarProduto("Mario", 5.0, 100);

    carrinho.adicionarItem(p1, 2); // 100
    carrinho.adicionarItem(p2, 4); // 20

    CHECK(carrinho.calcularTotal() == doctest::Approx(120.0));
}

TEST_CASE("CarrinhoDeCompras: remover produto existente") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Headset", 89.90, 5);

    carrinho.adicionarItem(produto, 1);
    REQUIRE(carrinho.getItens().size() == 1);

    carrinho.removerproduto(produto);
    CHECK(carrinho.getItens().empty());
}

TEST_CASE("CarrinhoDeCompras: remover produto inexistente nao altera o carrinho") {
    CarrinhoDeCompras carrinho;
    auto p1 = criarProduto("Jogo A", 10.0, 5);
    auto p2 = criarProduto("Jogo B", 20.0, 5);

    carrinho.adicionarItem(p1, 1);
    carrinho.removerproduto(p2);

    CHECK(carrinho.getItens().size() == 1);
}

TEST_CASE("CarrinhoDeCompras: atualizar quantidade de item existente") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Controle", 120.0, 10);

    carrinho.adicionarItem(produto, 1);
    carrinho.atualizarQuantidade(produto, 4);

    REQUIRE(carrinho.getItens().size() == 1);
    CHECK(carrinho.getItens()[0].quantidade == 4);
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
    auto p1 = criarProduto("Jogo A", 10.0, 10);
    auto p2 = criarProduto("Jogo B", 20.0, 10);

    carrinho.adicionarItem(p1, 1);
    carrinho.adicionarItem(p2, 1);

    carrinho.esvaziar();

    CHECK(carrinho.getItens().empty());
    CHECK(carrinho.calcularTotal() == doctest::Approx(0.0));
}

TEST_CASE("CarrinhoDeCompras: adicionar produto nulo eh rejeitado") {
    CarrinhoDeCompras carrinho;

    CHECK(carrinho.adicionarItem(nullptr, 1) == false);
    CHECK(carrinho.getItens().empty());
}

TEST_CASE("CarrinhoDeCompras: adicionar quantidade invalida eh rejeitado") {
    CarrinhoDeCompras carrinho;
    auto produto = criarProduto("Jogo X", 10.0, 10);

    CHECK(carrinho.adicionarItem(produto, 0) == false);
    CHECK(carrinho.adicionarItem(produto, -3) == false);
    CHECK(carrinho.getItens().empty());
}
