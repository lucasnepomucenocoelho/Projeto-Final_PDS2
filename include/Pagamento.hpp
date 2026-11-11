#ifndef PAGAMENTO_HPP
#define PAGAMENTO_HPP

/**
 * @brief Formas de pagamento aceitas pela loja.
 */
enum class FormaPagamento { CARTAO, BOLETO, PIX };

/**
 * @brief Status possíveis de um pagamento.
 */
enum class StatusPagamento { PENDENTE, APROVADO, RECUSADO };

/**
 * @class Pagamento
 * @brief Representa o pagamento associado a um pedido.
 */
class Pagamento {
public:
    /**
     * @brief Construtor da classe Pagamento.
     * @param valor Valor total a ser pago.
     * @param forma Forma de pagamento escolhida.
     * @throws std::invalid_argument se o valor for menor ou igual a zero.
     */
    Pagamento(double valor, FormaPagamento forma);

    /**
     * @brief Processa/valida a transação de pagamento.
     * @return true se aprovado, false caso contrário.
     */
    bool processar();

    /**
     * @brief Retorna o status atual do pagamento.
     */
    StatusPagamento getStatus() const;

    /**
     * @brief Retorna o valor do pagamento.
     */
    double getValor() const;

    /**
     * @brief Retorna a forma de pagamento escolhida.
     */
    FormaPagamento getForma() const;

private:
    double valor_;
    FormaPagamento forma_;
    StatusPagamento status_;
};

#endif // PAGAMENTO_HPP
