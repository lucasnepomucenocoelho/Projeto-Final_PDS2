#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include "Produto.hpp"
#include <memory>
#include <vector>

/**
 * @class Estoque
 * @brief Gerencia a quantidade disponível de cada produto do catálogo.
 */
class Estoque {
public:
    /**
     * @brief Adiciona um novo produto ao estoque/catálogo.
     */
    void adicionarProduto(std::shared_ptr<Produto> produto);

    /**
     * @brief Verifica se há quantidade suficiente de um produto.
     */
    bool verificarDisponibilidade(const std::shared_ptr<Produto>& produto,
                                   int quantidade) const;

    /**
     * @brief Dá baixa na quantidade de um produto após uma venda.
     */
    void darBaixa(const std::shared_ptr<Produto>& produto, int quantidade);

    /**
     * @brief Repõe/atualiza manualmente a quantidade de um produto
     * (uso administrativo ou após aprovação de uma SolicitacaoVenda).
     */
    void reporQuantidade(const std::shared_ptr<Produto>& produto, int quantidade);

    /**
     * @brief Retorna todos os produtos cadastrados.
     */
    const std::vector<std::shared_ptr<Produto>>& listarProdutos() const;

    /**
     * @brief Remove um produto do catálogo.
     * @return true se removido, false se houver pedidos pendentes associados.
     */
    bool removerProduto(const std::shared_ptr<Produto>& produto);

private:
    std::vector<std::shared_ptr<Produto>> produtos_;
};

#endif // ESTOQUE_HPP
