#include "Acessorio.hpp"

Acessorio::Acessorio(const std::string& titulo, const std::string& plataforma,
                      double preco, Condicao condicao, int quantidadeEstoque,
                      const std::string& tipo, const std::string& compativelCom)
    : Produto(titulo, plataforma, preco, condicao, quantidadeEstoque),
      tipo_(tipo), compativelCom_(compativelCom) {}

std::string Acessorio::getCategoria() const { return "Acessorio"; }

std::string Acessorio::getDescricaoDetalhada() const {
    // TODO (C8): montar descricao completa (titulo, tipo, compatibilidade etc.).
    return "";
}

std::string Acessorio::getTipo() const { return tipo_; }
