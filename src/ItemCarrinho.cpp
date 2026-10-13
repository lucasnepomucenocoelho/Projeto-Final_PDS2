#include "ItemCarrinho.hpp"

double ItemCompra::subtotal() const {
    if (!produto) return 0.0;
    return produto->getPreco() * quantidade;
}
