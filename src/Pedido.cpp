#include "Pedido.hpp"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

/**
 * @brief Construtor da classe Pedido.
 * Inicializa a lista de itens, o endereço de entrega, o pagamento e o status.
 * Também gera a data e hora atual da criação do pedido.
 * @param itens Vetor de itens que compõem o pedido.
 * @param enderecoEntrega Endereço para onde o pedido será enviado.
 * @param pagamento Objeto de pagamento associado.
 */
Pedido::Pedido(const std::vector<ItemCompra>& itens,
               const std::string& enderecoEntrega, const Pagamento& pagamento)
    : itens_(itens), enderecoEntrega_(enderecoEntrega), pagamento_(pagamento),
      status_(StatusPedido::PENDENTE), data_("") {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%d/%m/%Y %H:%M");
    data_ = ss.str();
}

/**
 * @brief Calcula o valor total do pedido somando o subtotal de cada item.
 * @return O valor total do pedido.
 */
double Pedido::calcularTotal() const {
    double total = 0.0;
    for (const auto& item : itens_) {
        total += item.subtotal();
    }
    return total;
}

/**
 * @brief Tenta processar o pagamento associado ao pedido.
 * Só permite o processamento se o status atual for PENDENTE.
 * @return true se o pagamento for aprovado, false caso contrário.
 */
bool Pedido::processarPagamento() {
    if (status_ != StatusPedido::PENDENTE) return false;
    return pagamento_.processar();
}

/**
 * @brief Atualiza o status do pedido.
 * @param novoStatus O novo status (ENVIADO, ENTREGUE, etc.).
 */
void Pedido::atualizarStatus(StatusPedido novoStatus) { 
    status_ = novoStatus; 
}

/**
 * @brief Cancela o pedido.
 * Só é permitido cancelar se o pedido ainda estiver PENDENTE.
 * @return true se cancelado com sucesso, false se já tiver sido enviado ou cancelado.
 */
bool Pedido::cancelar() {
    if (status_ == StatusPedido::PENDENTE) {
        status_ = StatusPedido::CANCELADO;
        return true;
    }
    return false;
}

StatusPedido Pedido::getStatus() const { return status_; }
const std::vector<ItemCompra>& Pedido::getItens() const { return itens_; }
std::string Pedido::getEnderecoEntrega() const { return enderecoEntrega_; }
