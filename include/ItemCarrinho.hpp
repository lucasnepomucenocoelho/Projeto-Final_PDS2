#ifndef ITEM_CARRINHO_HPP
#define ITEM_CARRINHO_HPP

#include "Produto.hpp"
#include <memory>

/**
 * @struct ItemCompra
 * @brief Associa um produto a uma quantidade, usado no carrinho e no pedido.
 */
struct ItemCompra {
    std::shared_ptr<Produto> produto; ///< Ponteiro para o produto.
    int quantidade;                   ///< Quantidade do produto.

    /**
     * @brief Calcula o subtotal do item (preço unitário * quantidade).
     * @return O valor total do item.
     */
    double subtotal() const;
};

#endif // ITEM_CARRINHO_HPP
