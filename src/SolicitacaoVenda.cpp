#include "SolicitacaoVenda.hpp"

SolicitacaoVenda::SolicitacaoVenda(const std::string& clienteId,
                                    const std::string& descricaoProduto,
                                    double precoSugerido)
    : clienteId_(clienteId), descricaoProduto_(descricaoProduto),
      precoSugerido_(precoSugerido), precoFinal_(0.0),
      status_(StatusSolicitacao::EM_ANALISE), justificativaRecusa_("") {}

std::shared_ptr<Produto> SolicitacaoVenda::aprovar(double precoFinal) {
    // TODO (C8): atribuir precoFinal_, status_ = APROVADA e criar o Produto
    // concreto (Jogo/Console/Acessorio) a partir de descricaoProduto_.
    (void)precoFinal;
    return nullptr;
}

void SolicitacaoVenda::recusar(const std::string& justificativa) {
    // TODO (C8): atribuir justificativaRecusa_ e status_ = RECUSADA.
    (void)justificativa;
}

StatusSolicitacao SolicitacaoVenda::getStatus() const { return status_; }
std::string SolicitacaoVenda::getClienteId() const { return clienteId_; }
double SolicitacaoVenda::getPrecoFinal() const { return precoFinal_; }
