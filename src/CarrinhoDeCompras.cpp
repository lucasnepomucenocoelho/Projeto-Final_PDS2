#include "CarrinhoDeCompras.hpp"

bool CarrinhoDeCompras::adicionarItem(std::shared_ptr<Produto> produto, int quantidade) {
    // TODO (C8): validar disponibilidade em estoque e adicionar a itens_.
    return false;
}

void CarrinhoDeCompras::removerproduto(const std::shared_ptr<Produto>& produto) {
    // TODO (C8): remover produto de itens_.
}

void CarrinhoDeCompras::atualizarQuantidade(const std::shared_ptr<Produto>& produto,
                                             int novaQuantidade) {
    // TODO (C8): localizar item e atualizar quantidade.
}

double CarrinhoDeCompras::calcularTotal() const {
    // TODO (C8): somar o subtotal de cada item em itens_.
    return 0.0;
}

const std::vector<ItemCompra>& CarrinhoDeCompras::getItens() const { return itens_; }

void CarrinhoDeCompras::esvaziar() {
    // TODO (C8): limpar itens_.
}