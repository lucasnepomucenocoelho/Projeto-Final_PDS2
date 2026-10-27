#include "Pagamento.hpp"

Pagamento::Pagamento(double valor, FormaPagamento forma)
    : valor_(valor), forma_(forma), status_(StatusPagamento::PENDENTE) {}

bool Pagamento::processar() {
    if (valor_ <= 0.0) {
        status_ = StatusPagamento::RECUSADO;
        return false;
    }
    switch (forma_) {
        case FormaPagamento::PIX:
        case FormaPagamento::CARTAO:
            status_ = StatusPagamento::APROVADO;
            return true;
        case FormaPagamento::BOLETO:
            status_ = StatusPagamento::PENDENTE;
            return false;
    }
    return false;
}

StatusPagamento Pagamento::getStatus() const { return status_; }
double Pagamento::getValor() const { return valor_; }
FormaPagamento Pagamento::getForma() const { return forma_; }
