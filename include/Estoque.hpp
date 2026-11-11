#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include "Produto.hpp"
#include <memory>
#include <vector>

/**
 * @class Estoque
 * @brief Gerencia a quantidade disponível de cada produto do catálogo.
 * Responsável por adicionar, remover e controlar a disponibilidade
 * dos itens vendidos na loja.
 */
class Estoque {
public:
    /**
     * @brief Adiciona um novo produto ao estoque/catálogo.
     * @param produto Ponteiro compartilhado para o produto a ser adicionado.
     */
    void adicionarProduto(std::shared_ptr<Produto> produto);

    /**
     * @brief Verifica se há quantidade suficiente de um produto.
     * @param produto O produto a ser verificado.
     * @param quantidade A quantidade desejada.
     * @return true se houver estoque suficiente, false caso contrário.
     */
    bool verificarDisponibilidade(const std::shared_ptr<Produto>& produto,
                                   int quantidade) const;

    /**
     * @brief Dá baixa na quantidade de um produto após uma venda.
     * @param produto O produto vendido.
     * @param quantidade A quantidade vendida.
     */
    void darBaixa(const std::shared_ptr<Produto>& produto, int quantidade);

    /**
     * @brief Repõe/atualiza manualmente a quantidade de um produto.
     * @param produto O produto a ser reposto.
     * @param quantidade A nova quantidade em estoque.
     */
    void reporQuantidade(const std::shared_ptr<Produto>& produto, int quantidade);

    /**
     * @brief Retorna todos os produtos cadastrados no estoque.
     * @return Um vetor constante de ponteiros para os produtos.
     */
    const std::vector<std::shared_ptr<Produto>>& listarProdutos() const;

    /**
     * @brief Remove um produto do catálogo.
     * @param produto O produto a ser removido.
     * @return true se removido com sucesso, false se não encontrado.
     */
    bool removerProduto(const std::shared_ptr<Produto>& produto);

private:
    std::vector<std::shared_ptr<Produto>> produtos_; ///< Lista de produtos em estoque.
};

#endif // ESTOQUE_HPP
