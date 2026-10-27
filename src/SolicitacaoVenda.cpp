#include "SolicitacaoVenda.hpp"
#include "Jogo.hpp"

SolicitacaoVenda::SolicitacaoVenda(const std::string& clienteId,
                                    const std::string& descricaoProduto,
                                    double precoSugerido)
    : clienteId_(clienteId), descricaoProduto_(descricaoProduto),
      precoSugerido_(precoSugerido), precoFinal_(0.0),
      status_(StatusSolicitacao::EM_ANALISE), justificativaRecusa_("") {}

std::shared_ptr<Produto> SolicitacaoVenda::aprovar(double precoFinal) {
    precoFinal_ = precoFinal;
    status_ = StatusSolicitacao::APROVADA;
    return std::make_shared<Jogo>(descricaoProduto_, "N/A", precoFinal,
                                   Condicao::USADO, 1, "N/A", "L");
}

void SolicitacaoVenda::recusar(const std::string& justificativa) {
    justificativaRecusa_ = justificativa;
    status_ = StatusSolicitacao::RECUSADA;
}

StatusSolicitacao SolicitacaoVenda::getStatus() const { return status_; }
std::string SolicitacaoVenda::getClienteId() const { return clienteId_; }
double SolicitacaoVenda::getPrecoFinal() const { return precoFinal_; }
