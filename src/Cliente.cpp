#include "Cliente.hpp"

Cliente::Cliente(const std::string& nome, const std::string& email,
                  const std::string& senha, const std::string& endereco)
    : nome_(nome), email_(email), senha_(senha), endereco_(endereco) {}

bool Cliente::autenticar(const std::string& email, const std::string& senha) const {
    return email_ == email && senha_ == senha;
}

void Cliente::editarPerfil(const std::string& nome, const std::string& email,
                            const std::string& endereco) {
    nome_ = nome;
    email_ = email;
    endereco_ = endereco;
}

CarrinhoDeCompras& Cliente::getCarrinho() { return carrinho_; }

Pedido Cliente::finalizarPedido(const std::string& enderecoEntrega,
                                 const Pagamento& pagamento) {
    Pedido p(carrinho_.getItens(), enderecoEntrega, pagamento);
    historicoPedidos_.push_back(p);
    carrinho_.esvaziar();
    return p;
}

const std::vector<Pedido>& Cliente::getHistoricoPedidos() const {
    return historicoPedidos_;
}

SolicitacaoVenda Cliente::criarSolicitacaoVenda(const std::string& descricaoProduto,
                                                 double precoSugerido) {
    SolicitacaoVenda s(email_, descricaoProduto, precoSugerido);
    solicitacoesVenda_.push_back(s);
    return s;
}

const std::vector<SolicitacaoVenda>& Cliente::getSolicitacoesVenda() const {
    return solicitacoesVenda_;
}

std::string Cliente::getNome() const { return nome_; }
std::string Cliente::getEmail() const { return email_; }
