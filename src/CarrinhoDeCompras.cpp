#include "CarrinhoDeCompras.hpp"
#include <algorithm>

bool CarrinhoDeCompras::adicionarItem(std::shared_ptr<Produto> produto, int quantidade) {
    if (!produto || quantidade <= 0) {
        return false;
    }

    // Procura se o produto já está no carrinho
    auto it = std::find_if(itens_.begin(), itens_.end(),
                           [&](const ItemCompra& item) {
                               return item.produto == produto;
                           });

    const int quantidadeNoCarrinho = (it != itens_.end()) ? it->quantidade : 0;
    const int quantidadeDesejada = quantidadeNoCarrinho + quantidade;

    // Valida o estoque considerando o que já está no carrinho
    if (!produto->verificarDisponibilidade(quantidadeDesejada)) {
        return false;
    }

    if (it != itens_.end()) {
        it->quantidade = quantidadeDesejada;
    } else {
        itens_.push_back(ItemCompra{produto, quantidade});
    }
    return true;
}

void CarrinhoDeCompras::removerproduto(const std::shared_ptr<Produto>& produto) {
    itens_.erase(
        std::remove_if(itens_.begin(), itens_.end(),
                       [&](const ItemCompra& item) {
                           return item.produto == produto;
                       }),
        itens_.end());
}

void CarrinhoDeCompras::atualizarQuantidade(const std::shared_ptr<Produto>& produto,
                                             int novaQuantidade) {
    if (!produto) {
        return;
    }

    auto it = std::find_if(itens_.begin(), itens_.end(),
                           [&](const ItemCompra& item) {
                               return item.produto == produto;
                           });

    if (it == itens_.end()) {
        return; // produto não está no carrinho
    }

    // Quantidade zero ou negativa equivale a remover o item
    if (novaQuantidade <= 0) {
        itens_.erase(it);
        return;
    }

    // Se não houver estoque suficiente, mantém a quantidade atual
    if (!produto->verificarDisponibilidade(novaQuantidade)) {
        return;
    }

    it->quantidade = novaQuantidade;
}

double CarrinhoDeCompras::calcularTotal() const {
    double total = 0.0;
    for (const auto& item : itens_) {
        total += item.subtotal();
    }
    return total;
}

const std::vector<ItemCompra>& CarrinhoDeCompras::getItens() const { return itens_; }

void CarrinhoDeCompras::esvaziar() {
    itens_.clear();
}