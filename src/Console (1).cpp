#include "Console.hpp"

Console::Console(const std::string& titulo, const std::string& plataforma,
                  double preco, Condicao condicao, int quantidadeEstoque,
                  int capacidadeArmazenamento, bool acompanhaControle)
    : Produto(titulo, plataforma, preco, condicao, quantidadeEstoque),
      capacidadeArmazenamento_(capacidadeArmazenamento),
      acompanhaControle_(acompanhaControle) {}

std::string Console::getCategoria() const { return "Console"; }

std::string Console::getDescricaoDetalhada() const {
    // TODO (C8): montar descricao completa (titulo, armazenamento etc.).
    return "";
}

int Console::getCapacidadeArmazenamento() const { return capacidadeArmazenamento_; }
