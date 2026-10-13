#include "Jogo.hpp"

Jogo::Jogo(const std::string& titulo, const std::string& plataforma,
           double preco, Condicao condicao, int quantidadeEstoque,
           const std::string& genero, const std::string& classificacaoIndicativa)
    : Produto(titulo, plataforma, preco, condicao, quantidadeEstoque),
      genero_(genero), classificacaoIndicativa_(classificacaoIndicativa) {}

std::string Jogo::getCategoria() const { return "Jogo"; }

std::string Jogo::getDescricaoDetalhada() const {
    // TODO (C8): montar descricao completa (titulo, genero, classificacao etc.).
    return "";
}

std::string Jogo::getGenero() const { return genero_; }
