# CRC Cards

## Classe: Carrinho
**Responsabilidades**
- Adicionar produto com quantidade
- Remover produto
- Atualizar quantidade de um item
- Calcular valor total
- Validar quantidade solicitada contra o estoque disponível
- Esvaziar carrinho

**Colaboradores**
- ItemCarrinho
- Produto
- Estoque
- Pedido

---

## Classe: ItemCarrinho
**Responsabilidades**
- Armazenar produto e quantidade
- Calcular subtotal do item

**Colaboradores**
- Produto


## Classe: Pagamento
**Responsabilidades**
- Representar a forma de pagamento escolhida (cartão, boleto, pix)
- Validar/processar o pagamento

**Colaboradores**
- Pedido