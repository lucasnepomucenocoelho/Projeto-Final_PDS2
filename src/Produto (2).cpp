#include "Produto.hpp"

Produto::Produto(const std::string& titulo, const std::string& plataforma,
                  double preco, Condicao condicao, int quantidadeEstoque)
    : titulo_(titulo), plataforma_(plataforma), preco_(preco),
      condicao_(condicao), quantidadeEstoque_(quantidadeEstoque) {}

bool Produto::verificarDisponibilidade(int quantidade) const {
    // TODO (C8): comparar quantidade com quantidadeEstoque_.
    (void)quantidade;
    return false;
}

bool Produto::estaEsgotado() const {
    // TODO (C8): retornar quantidadeEstoque_ == 0.
    return false;
}

void Produto::atualizarPreco(double novoPreco) {
    // TODO (C8): validar e atribuir a preco_.
    (void)novoPreco;
}

std::string Produto::getTitulo() const { return titulo_; }
std::string Produto::getPlataforma() const { return plataforma_; }
double Produto::getPreco() const { return preco_; }
Condicao Produto::getCondicao() const { return condicao_; }
int Produto::getQuantidadeEstoque() const { return quantidadeEstoque_; }
void Produto::setQuantidadeEstoque(int quantidade) { quantidadeEstoque_ = quantidade; }
