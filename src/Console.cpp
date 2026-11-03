#include "Console.hpp"
#include <sstream>
#include <stdexcept>

Console::Console(const std::string& titulo, const std::string& plataforma,
                  double preco, Condicao condicao, int quantidadeEstoque,
                  int capacidadeArmazenamento, bool acompanhaControle)
    : Produto(titulo, plataforma, preco, condicao, quantidadeEstoque),
      capacidadeArmazenamento_(capacidadeArmazenamento),
      acompanhaControle_(acompanhaControle) {
    if (capacidadeArmazenamento <= 0) {
        throw std::invalid_argument("A capacidade de armazenamento deve ser maior que zero");
    }
}

std::string Console::getCategoria() const { return "Console"; }

std::string Console::getDescricaoDetalhada() const {
    std::ostringstream oss;
    oss << "Console: " << titulo_
        << " | Plataforma: " << plataforma_
        << " | Armazenamento: " << capacidadeArmazenamento_ << "GB"
        << " | Acompanha controle: " << (acompanhaControle_ ? "Sim" : "Nao")
        << " | Preco: R$ " << preco_
        << " | Condicao: " << (condicao_ == Condicao::NOVO ? "Novo" : "Usado")
        << " | Estoque: " << quantidadeEstoque_;
    return oss.str();
}

int Console::getCapacidadeArmazenamento() const { return capacidadeArmazenamento_; }
