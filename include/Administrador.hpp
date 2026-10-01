#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Estoque.hpp"
#include "SolicitacaoVenda.hpp"
#include "Pedido.hpp"
#include <string>
#include <vector>

/**
 * @class Administrador
 * @brief Responsável por gerenciar o catálogo, avaliar solicitações
 * de venda e gerar relatórios da loja.
 */
class Administrador {
public:
    Administrador(const std::string& nome, const std::string& email,
                  const std::string& senha);

    bool autenticar(const std::string& email, const std::string& senha) const;

    /**
     * @brief Cadastra um novo produto no estoque.
     */
    void cadastrarProduto(std::shared_ptr<Produto> produto, Estoque& estoque);

    /**
     * @brief Remove um produto do catálogo.
     * @return true se removido, false se houver pedidos pendentes associados.
     */
    bool removerProduto(std::shared_ptr<Produto> produto, Estoque& estoque);

    /**
     * @brief Avalia uma solicitação de venda, aprovando ou recusando.
     * Quando aprovada, o produto resultante é adicionado ao estoque.
     */
    void avaliarSolicitacao(SolicitacaoVenda& solicitacao, bool aprovar,
                             double precoFinal, Estoque& estoque);

    /**
     * @brief Gera um relatório de vendas em um período (total, produtos
     * mais vendidos, ticket médio).
     */
    std::string gerarRelatorioVendas(const std::vector<Pedido>& pedidos) const;

private:
    std::string nome_;
    std::string email_;
    std::string senha_;
};

#endif // ADMINISTRADOR_HPP
