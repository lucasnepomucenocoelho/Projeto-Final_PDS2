#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "ItemCarrinho.hpp"
#include "Pagamento.hpp"
#include <vector>
#include <string>

/**
 * @brief Status possíveis de um pedido.
 */
enum class StatusPedido { PENDENTE, ENVIADO, ENTREGUE, CANCELADO };

/**
 * @class Pedido
 * @brief Representa um pedido de compra finalizado por um cliente.
 */
class Pedido {
public:
    /**
     * @brief Construtor da classe Pedido.
     * @param itens Itens que compõem o pedido.
     * @param enderecoEntrega Endereço de entrega escolhido.
     * @param pagamento Pagamento associado ao pedido.
     */
    Pedido(const std::vector<ItemCompra>& itens,
           const std::string& enderecoEntrega, const Pagamento& pagamento);

    /**
     * @brief Calcula o valor total do pedido.
     */
    double calcularTotal() const;

    /**
     * @brief Solicita o processamento do pagamento associado.
     */
    bool processarPagamento();

    /**
     * @brief Atualiza o status do pedido.
     */
    void atualizarStatus(StatusPedido novoStatus);

    /**
     * @brief Cancela o pedido, caso ainda esteja pendente.
     * @return true se cancelado, false se já tiver sido enviado.
     */
    bool cancelar();

    StatusPedido getStatus() const;
    const std::vector<ItemCompra>& getItens() const;
    std::string getEnderecoEntrega() const;

private:
    std::vector<ItemCompra> itens_;
    std::string enderecoEntrega_;
    Pagamento pagamento_;
    StatusPedido status_;
    std::string data_;
};

#endif // PEDIDO_HPP
