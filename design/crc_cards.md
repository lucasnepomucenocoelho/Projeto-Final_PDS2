# CRC Cards

---

## Classe: ItemCarrinho
**Responsabilidades**
- Armazenar produto e quantidade
- Calcular subtotal do item

**Colaboradores**
- Produto

---

## Classe: Pagamento
**Responsabilidades**
- Representar a forma de pagamento escolhida (cartão, boleto, pix)
- Validar/processar o pagamento

**Colaboradores**
- Pedido

---

## Classe: Cliente
**Responsabilidades**
- Manter cadastro de endereços de entrega
- Selecionar endereço de entrega para o pedido
- Acessar seu carrinho de compras

**Colaboradores**
- Endereco
- Carrinho

---

## Classe: Produto
**Responsabilidades**
- Fornecer preço por unidade
- Informar quantidade disponível em estoque
- Verificar se há estoque suficiente para uma quantidade pedida

**Colaboradores**
- Estoque 

---

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
