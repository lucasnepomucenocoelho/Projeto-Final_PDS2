#include "Estoque.hpp"
#include <algorithm>

void Estoque::adicionarProduto(std::shared_ptr<Produto> produto) {
    if (produto) produtos_.push_back(produto);
}

bool Estoque::verificarDisponibilidade(const std::shared_ptr<Produto>& produto, int quantidade) const {
    if (!produto) return false;
    return produto->verificarDisponibilidade(quantidade);
}

void Estoque::darBaixa(const std::shared_ptr<Produto>& produto, int quantidade) {
    if (!produto || quantidade <= 0) return;
    int atual = produto->getQuantidadeEstoque();
    produto->setQuantidadeEstoque(atual - quantidade);
}

void Estoque::reporQuantidade(const std::shared_ptr<Produto>& produto, int quantidade) {
    if (!produto || quantidade < 0) return;
    produto->setQuantidadeEstoque(quantidade);
}

const std::vector<std::shared_ptr<Produto>>& Estoque::listarProdutos() const {
    return produtos_;
}

bool Estoque::removerProduto(const std::shared_ptr<Produto>& produto) {
    if (!produto) return false;
    auto it = std::remove(produtos_.begin(), produtos_.end(), produto);
    if (it == produtos_.end()) return false;
    produtos_.erase(it, produtos_.end());
    return true;
}
