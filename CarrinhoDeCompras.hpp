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
     * @return true se adicionado, false se não há estoque suficiente.
     */
    bool adicionarItem(std::shared_ptr<Produto> produto, int quantidade);

    /**
     * @brief Remove um produto do carrinho.
     */
    void removerproduto(const std::shared_ptr<Produto>& produto);

    /**
     * @brief Atualiza a quantidade de um item já presente no carrinho.
     */
    void atualizarQuantidade(const std::shared_ptr<Produto>& produto, int novaQuantidade);

    /**
     * @brief Calcula o valor total do carrinho.
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
    std::vector<ItemCompra> itens_;
};

#endif // CARRINHO_DE_COMPRAS_HPP
