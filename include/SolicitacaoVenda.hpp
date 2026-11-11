#ifndef SOLICITACAO_VENDA_HPP
#define SOLICITACAO_VENDA_HPP

#include "Produto.hpp"
#include <string>
#include <memory>

/**
 * @brief Status possíveis de uma solicitação de venda.
 */
enum class StatusSolicitacao { EM_ANALISE, APROVADA, RECUSADA };

/**
 * @class SolicitacaoVenda
 * @brief Representa a oferta de um cliente para vender um produto usado à loja.
 */
class SolicitacaoVenda {
public:
    /**
     * @brief Construtor da classe SolicitacaoVenda.
     * @param clienteId Identificador (email) do cliente vendedor.
     * @param descricaoProduto Descrição do produto ofertado.
     * @param precoSugerido Preço sugerido pelo cliente.
     */
    SolicitacaoVenda(const std::string& clienteId,
                      const std::string& descricaoProduto, double precoSugerido);

    /**
     * @brief Aprova a solicitação, definindo o preço final de compra.
     * @param precoFinal Valor final pago ao cliente pelo produto.
     * @return O produto criado a partir da solicitação aprovada, pronto
     * para ser adicionado ao Estoque.
     */
    std::shared_ptr<Produto> aprovar(double precoFinal);

    /**
     * @brief Recusa a solicitação.
     * @param justificativa Motivo da recusa.
     */
    void recusar(const std::string& justificativa);

    /**
     * @brief Retorna o status atual da solicitação.
     */
    StatusSolicitacao getStatus() const;

    /**
     * @brief Retorna o identificador do cliente vendedor.
     */
    std::string getClienteId() const;

    /**
     * @brief Retorna o preço final definido pelo administrador.
     */
    double getPrecoFinal() const;

private:
    std::string clienteId_;
    std::string descricaoProduto_;
    double precoSugerido_;
    double precoFinal_;
    StatusSolicitacao status_;
    std::string justificativaRecusa_;
};

#endif // SOLICITACAO_VENDA_HPP
