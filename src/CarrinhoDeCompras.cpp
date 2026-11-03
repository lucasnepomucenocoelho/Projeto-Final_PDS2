#include "CarrinhoDeCompras.hpp"
#include <algorithm>
#include <stdexcept>

bool CarrinhoDeCompras::adicionarItem(std::shared_ptr<Produto> produto, int quantidade) {
    if (!produto) {
        throw std::invalid_argument("O produto nao pode ser nulo.");
    }
    if (quantidade <= 0) {
        throw std::invalid_argument("A quantidade deve ser maior que zero.");
    }

    auto it = std::find_if(itens_.begin(), itens_.end(),
                           [&](const ItemCompra& item) {
                               return item.produto == produto;
                           });

    const int quantidadeNoCarrinho = (it != itens_.end()) ? it->quantidade : 0;
    const int quantidadeDesejada = quantidadeNoCarrinho + quantidade;

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
    if (!produto) return;

    auto it = std::find_if(itens_.begin(), itens_.end(),
                           [&](const ItemCompra& item) {
                               return item.produto == produto;
                           });

    if (it == itens_.end()) return;

    if (novaQuantidade <= 0) {
        itens_.erase(it);
        return;
    }

    if (!produto->verificarDisponibilidade(novaQuantidade)) return;

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
