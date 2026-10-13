#include "Pedido.hpp"

Pedido::Pedido(const std::vector<ItemCompra>& itens,
               const std::string& enderecoEntrega, const Pagamento& pagamento)
    : itens_(itens), enderecoEntrega_(enderecoEntrega), pagamento_(pagamento),
      status_(StatusPedido::PENDENTE), data_("") {}

double Pedido::calcularTotal() const {
    // TODO (C8): somar o subtotal de cada item em itens_.
    return 0.0;
}

bool Pedido::processarPagamento() {
    // TODO (C8): delegar para pagamento_.processar().
    return false;
}

void Pedido::atualizarStatus(StatusPedido novoStatus) {
    // TODO (C8): atribuir a status_.
    (void)novoStatus;
}

bool Pedido::cancelar() {
    // TODO (C8): cancelar apenas se status_ == PENDENTE.
    return false;
}

StatusPedido Pedido::getStatus() const { return status_; }
const std::vector<ItemCompra>& Pedido::getItens() const { return itens_; }
std::string Pedido::getEnderecoEntrega() const { return enderecoEntrega_; }
