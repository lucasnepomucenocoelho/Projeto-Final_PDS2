#include "Estoque.hpp"

void Estoque::adicionarProduto(std::shared_ptr<Produto> produto) {
    // TODO (C8): adicionar produto a produtos_.
    (void)produto;
}

bool Estoque::verificarDisponibilidade(const std::shared_ptr<Produto>& produto,
                                        int quantidade) const {
    // TODO (C8): delegar para produto->verificarDisponibilidade(quantidade).
    (void)produto;
    (void)quantidade;
    return false;
}

void Estoque::darBaixa(const std::shared_ptr<Produto>& produto, int quantidade) {
    // TODO (C8): reduzir a quantidade em estoque do produto.
    (void)produto;
    (void)quantidade;
}

void Estoque::reporQuantidade(const std::shared_ptr<Produto>& produto, int quantidade) {
    // TODO (C8): atualizar a quantidade em estoque do produto.
    (void)produto;
    (void)quantidade;
}

const std::vector<std::shared_ptr<Produto>>& Estoque::listarProdutos() const {
    return produtos_;
}

bool Estoque::removerProduto(const std::shared_ptr<Produto>& produto) {
    // TODO (C8): remover produto de produtos_, validando pedidos pendentes.
    (void)produto;
    return false;
}
