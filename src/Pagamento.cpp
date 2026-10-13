#include "Pagamento.hpp"

Pagamento::Pagamento(double valor, FormaPagamento forma)
    : valor_(valor), forma_(forma), status_(StatusPagamento::PENDENTE) {}

bool Pagamento::processar() {
    // TODO (C8): simular processamento e atualizar status_.
    return false;
}

StatusPagamento Pagamento::getStatus() const { return status_; }
double Pagamento::getValor() const { return valor_; }
FormaPagamento Pagamento::getForma() const { return forma_; }
