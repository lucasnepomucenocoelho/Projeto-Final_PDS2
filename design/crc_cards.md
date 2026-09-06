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

---

## Classe: Produto
**Responsabilidades**
- Fornecer preço unitário
- Fornecer quantidade em estoque

**Colaboradores**
- Estoque

---

## Classe: Estoque
**Responsabilidades**
- Informar quantidade disponível de um produto
- Dar baixa (decrementar) após confirmação do pedido

**Colaboradores**
- Produto
- Pedido

---

## Classe: Pedido
**Responsabilidades**
- Gerar pedido a partir dos itens do carrinho
- Registrar endereço de entrega escolhido
- Registrar forma de pagamento escolhida
- Solicitar baixa de estoque dos itens comprados
- Solicitar esvaziamento do carrinho após confirmação

**Colaboradores**
- Carrinho
- Cliente
- Endereco
- Pagamento
- Estoque

---

## Classe: Cliente
**Responsabilidades**
- Possuir endereços de entrega cadastrados
- Possuir um carrinho de compras

**Colaboradores**
- Endereco
- Carrinho

---

## Classe: Endereco
**Responsabilidades**
- Armazenar dados de entrega

**Colaboradores**
- Cliente

---

## Classe: Pagamento
**Responsabilidades**
- Representar a forma de pagamento escolhida (cartão, boleto, pix)
- Validar/processar o pagamento

**Colaboradores**
- Pedido