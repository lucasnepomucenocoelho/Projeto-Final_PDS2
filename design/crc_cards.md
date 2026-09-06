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

---

## Classe: Pedido
 
Responsabilidades
- Armazenar itens comprados, valores e data.
- Armazenar o endereço de entrega escolhido.
- Manter o status do pedido (pendente, enviado, entregue, cancelado).
- Calcular o valor total do pedido.
- Solicitar o processamento do pagamento.
- Solicitar a baixa no estoque dos itens comprados.
- Permitir o cancelamento do pedido caso ainda esteja pendente.

Colaborações: Cliente, Pagamento, Estoque

---

## Classe: SolicitacaoVenda

Responsabilidades
- Armazenar os dados do produto ofertado pelo cliente (tipo, plataforma, condição e preço sugerido).
- Manter o status da solicitação (em análise, aprovada, recusada).
- Armazenar o preço final definido pelo administrador.
- Gerar um novo Produto no catálogo quando a solicitação for aprovada.
- Vincular-se ao cliente vendedor.

Colaborações: Cliente, Produto, Estoque