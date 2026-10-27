#include "doctest.h"
#include "CarrinhoDeCompras.hpp"
#include "Jogo.hpp"

static std::shared_ptr<Produto> criarProduto(const std::string& nome, double preco, int estoque) {
    return std::make_shared<Jogo>(nome, "PS5", preco, Condicao::NOVO, estoque, "RPG", "L");
}

TEST_CASE("Carrinho - adicionar e calcular") {
    CarrinhoDeCompras c;
    auto jogo = criarProduto("Elden", 100.0, 10);
    CHECK(c.adicionarItem(jogo, 2) == true);
    CHECK(c.calcularTotal() == doctest::Approx(200.0));
    
    // Testa acumular item
    CHECK(c.adicionarItem(jogo, 1) == true);
    CHECK(c.getItens()[0].quantidade == 3);
}

TEST_CASE("Carrinho - remover e esvaziar") {
    CarrinhoDeCompras c;
    auto jogo = criarProduto("Mario", 50.0, 10);
    c.adicionarItem(jogo, 1);
    c.removerproduto(jogo);
    CHECK(c.getItens().empty());

    c.adicionarItem(jogo, 2);
    c.esvaziar();
    CHECK(c.getItens().empty());
}

TEST_CASE("Carrinho - atualizar quantidade") {
    CarrinhoDeCompras c;
    auto jogo = criarProduto("Zelda", 100.0, 10);
    c.adicionarItem(jogo, 1);
    
    c.atualizarQuantidade(jogo, 5); // Sucesso
    CHECK(c.getItens()[0].quantidade == 5);
    
    c.atualizarQuantidade(jogo, 0); // Remove
    CHECK(c.getItens().empty());
}

TEST_CASE("Carrinho - caminhos de erro") {
    CarrinhoDeCompras c;
    auto jogo = criarProduto("Teste", 10.0, 5);
    
    CHECK(c.adicionarItem(nullptr, 1) == false);
    CHECK(c.adicionarItem(jogo, -1) == false);
    
    c.atualizarQuantidade(nullptr, 5); // Cobre linha 52
    c.atualizarQuantidade(jogo, 2);    // Cobre linha 72
    
    c.adicionarItem(jogo, 1);
    c.atualizarQuantidade(jogo, 10); // Maior que estoque
    CHECK(c.getItens()[0].quantidade == 1);
}
