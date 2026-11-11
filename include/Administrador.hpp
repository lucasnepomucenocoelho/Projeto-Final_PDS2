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
    /**
     * @brief Construtor da classe Administrador.
     * @param nome Nome do administrador.
     * @param email Email de login.
     * @param senha Senha de acesso.
     */
    Administrador(const std::string& nome, const std::string& email,
                  const std::string& senha);

    /**
     * @brief Valida as credenciais de acesso do administrador.
     * @param email Email digitado.
     * @param senha Senha digitada.
     * @return true se as credenciais estiverem corretas.
     */
    bool autenticar(const std::string& email, const std::string& senha) const;

    /**
     * @brief Cadastra um novo produto no estoque.
     * @param produto Ponteiro para o produto a ser cadastrado.
     * @param estoque Referência ao estoque onde o produto será salvo.
     */
    void cadastrarProduto(std::shared_ptr<Produto> produto, Estoque& estoque);

    /**
     * @brief Remove um produto do catálogo.
     * @param produto Produto a ser removido.
     * @param estoque Referência ao estoque.
     * @return true se removido, false se houver pedidos pendentes associados.
     */
    bool removerProduto(std::shared_ptr<Produto> produto, Estoque& estoque);

    /**
     * @brief Avalia uma solicitação de venda, aprovando ou recusando.
     * Quando aprovada, o produto resultante é adicionado ao estoque.
     * @param solicitacao A solicitação a ser avaliada.
     * @param aprovar true para aprovar, false para recusar.
     * @param precoFinal Preço a ser pago ao cliente (se aprovado).
     * @param estoque Referência ao estoque.
     */
    void avaliarSolicitacao(SolicitacaoVenda& solicitacao, bool aprovar,
                             double precoFinal, Estoque& estoque);

    /**
     * @brief Gera um relatório de vendas em um período.
     * @param pedidos Vetor com os pedidos realizados.
     * @return Uma string formatada com o relatório (total e ticket médio).
     */
    std::string gerarRelatorioVendas(const std::vector<Pedido>& pedidos) const;

private:
    std::string nome_;
    std::string email_;
    std::string senha_;
};

#endif // ADMINISTRADOR_HPP
