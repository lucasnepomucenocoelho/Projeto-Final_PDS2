#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "CarrinhoDeCompras.hpp"
#include "Pedido.hpp"
#include "SolicitacaoVenda.hpp"
#include <string>
#include <vector>

/**
 * @class Cliente
 * @brief Representa um cliente da loja, capaz de comprar produtos
 * e vender produtos usados à loja.
 */
class Cliente {
public:
    /**
     * @brief Construtor da classe Cliente.
     */
    Cliente(const std::string& nome, const std::string& email,
            const std::string& senha, const std::string& endereco);

    /**
     * @brief Valida as credenciais informadas no login.
     */
    bool autenticar(const std::string& email, const std::string& senha) const;

    /**
     * @brief Atualiza os dados cadastrais do cliente.
     */
    void editarPerfil(const std::string& nome, const std::string& email,
                       const std::string& endereco);

    /**
     * @brief Retorna o carrinho de compras ativo do cliente.
     */
    CarrinhoDeCompras& getCarrinho();

    /**
     * @brief Finaliza o pedido a partir dos itens do carrinho atual.
     */
    Pedido finalizarPedido(const std::string& enderecoEntrega,
                            const Pagamento& pagamento);

    /**
     * @brief Retorna o histórico de pedidos do cliente.
     */
    const std::vector<Pedido>& getHistoricoPedidos() const;

    /**
     * @brief Cria uma nova solicitação de venda de um produto usado.
     */
    SolicitacaoVenda criarSolicitacaoVenda(const std::string& descricaoProduto,
                                            double precoSugerido);

    /**
     * @brief Retorna as solicitações de venda feitas pelo cliente.
     */
    const std::vector<SolicitacaoVenda>& getSolicitacoesVenda() const;

    std::string getNome() const;
    std::string getEmail() const;

private:
    std::string nome_;
    std::string email_;
    std::string senha_;
    std::string endereco_;
    CarrinhoDeCompras carrinho_;
    std::vector<Pedido> historicoPedidos_;
    std::vector<SolicitacaoVenda> solicitacoesVenda_;
};

#endif // CLIENTE_HPP
