#include "Acessorio.hpp"
#include <sstream>
#include <stdexcept>

Acessorio::Acessorio(const std::string& titulo, const std::string& plataforma,
                      double preco, Condicao condicao, int quantidadeEstoque,
                      const std::string& tipo, const std::string& compativelCom)
    : Produto(titulo, plataforma, preco, condicao, quantidadeEstoque),
      tipo_(tipo), compativelCom_(compativelCom) {
    if (tipo.empty()) throw std::invalid_argument("O tipo do acessorio nao pode ser vazio");
}

std::string Acessorio::getCategoria() const { return "Acessorio"; }

std::string Acessorio::getDescricaoDetalhada() const {
    std::ostringstream oss;
    oss << "Acessorio: " << titulo_
        << " | Tipo: " << tipo_
        << " | Plataforma: " << plataforma_
        << " | Compativel com: " << compativelCom_
        << " | Preco: R$ " << preco_
        << " | Condicao: " << (condicao_ == Condicao::NOVO ? "Novo" : "Usado")
        << " | Estoque: " << quantidadeEstoque_;
    return oss.str();
}

std::string Acessorio::getTipo() const { return tipo_; }
