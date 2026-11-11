#ifndef CARRINHO_DE_COMPRAS_HPP
#define CARRINHO_DE_COMPRAS_HPP

#include "ItemCarrinho.hpp"
#include <vector>
#include <memory>

/**
 * @class CarrinhoDeCompras
 * @brief Mantém os itens selecionados por um cliente antes do checkout.
 */
class CarrinhoDeCompras {
public:
    /**
     * @brief Adiciona um produto ao carrinho, validando disponibilidade em estoque.
     * @param produto O produto a ser adicionado.
     * @param quantidade A quantidade desejada.
     * @return true se adicionado, false se não há estoque suficiente.
     * @throws std::invalid_argument se produto for nulo ou quantidade <= 0.
     */
    bool adicionarItem(std::shared_ptr<Produto> produto, int quantidade);

    /**
     * @brief Remove um produto do carrinho.
     * @param produto O produto a ser removido.
     */
    void removerproduto(const std::shared_ptr<Produto>& produto);

    /**
     * @brief Atualiza a quantidade de um item já presente no carrinho.
     * @param produto O produto a ser atualizado.
     * @param novaQuantidade A nova quantidade desejada.
     */
    void atualizarQuantidade(const std::shared_ptr<Produto>& produto, int novaQuantidade);

    /**
     * @brief Calcula o valor total do carrinho.
     * @return O valor total em reais.
     */
    double calcularTotal() const;

    /**
     * @brief Retorna os itens atualmente no carrinho.
     */
    const std::vector<ItemCompra>& getItens() const;

    /**
     * @brief Esvazia o carrinho (usado após o checkout).
     */
    void esvaziar();

private:
    std::vector<ItemCompra> itens_; ///< Lista de itens no carrinho.
};

#endif // CARRINHO_DE_COMPRAS_HPP
