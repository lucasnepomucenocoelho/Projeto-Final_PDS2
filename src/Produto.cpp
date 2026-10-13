 #include "Produto.hpp"
#include <stdexcept>

Produto::Produto(const std::string& titulo, const std::string& plataforma,
                  double preco, Condicao condicao, int quantidadeEstoque)
    : titulo_(titulo), plataforma_(plataforma), preco_(preco),
      condicao_(condicao), quantidadeEstoque_(quantidadeEstoque) {
    if (preco < 0.0) throw std::invalid_argument("Preco nao pode ser negativo");
    if (quantidadeEstoque < 0) throw std::invalid_argument("Quantidade nao pode ser negativa");
}

bool Produto::verificarDisponibilidade(int quantidade) const {
    return quantidade > 0 && quantidadeEstoque_ >= quantidade;
}

bool Produto::estaEsgotado() const {
    return quantidadeEstoque_ <= 0;
}

void Produto::atualizarPreco(double novoPreco) {
    if (novoPreco < 0.0) throw std::invalid_argument("Preco nao pode ser negativo");
    preco_ = novoPreco;
}

std::string Produto::getTitulo() const { return titulo_; }
std::string Produto::getPlataforma() const { return plataforma_; }
double Produto::getPreco() const { return preco_; }
Condicao Produto::getCondicao() const { return condicao_; }
int Produto::getQuantidadeEstoque() const { return quantidadeEstoque_; }

void Produto::setQuantidadeEstoque(int quantidade) {
    if (quantidade < 0) throw std::invalid_argument("Quantidade nao pode ser negativa");
    quantidadeEstoque_ = quantidade;
}
