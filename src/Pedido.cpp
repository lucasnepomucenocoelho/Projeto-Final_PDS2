#include "Pedido.hpp"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

Pedido::Pedido(const std::vector<ItemCompra>& itens,
               const std::string& enderecoEntrega, const Pagamento& pagamento)
    : itens_(itens), enderecoEntrega_(enderecoEntrega), pagamento_(pagamento),
      status_(StatusPedido::PENDENTE), data_("") {
    // Gera a data e hora atual
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%d/%m/%Y %H:%M");
    data_ = ss.str();
}

double Pedido::calcularTotal() const {
    double total = 0.0;
    for (const auto& item : itens_) {
        total += item.subtotal();
    }
    return total;
}

bool Pedido::processarPagamento() {
    // Só processa se o pedido estiver pendente
    if (status_ != StatusPedido::PENDENTE) {
        return false;
    }
    return pagamento_.processar();
}

void Pedido::atualizarStatus(StatusPedido novoStatus) {
    status_ = novoStatus;
}

bool Pedido::cancelar() {
    // Só cancela se estiver pendente
    if (status_ == StatusPedido::PENDENTE) {
        status_ = StatusPedido::CANCELADO;
        return true;
    }
    return false;
}

StatusPedido Pedido::getStatus() const { return status_; }
const std::vector<ItemCompra>& Pedido::getItens() const { return itens_; }
std::string Pedido::getEnderecoEntrega() const { return enderecoEntrega_; }
