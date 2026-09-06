# User Stories

## US01 — Carrinho de compras

**Como** cliente,
**quero** adicionar e remover produtos do carrinho,
**para** montar meu pedido.

### Critérios de aceite
- Adicionar produto ao carrinho com quantidade.
- Atualizar quantidade de um item já adicionado.
- Remover produto do carrinho.
- Calcular valor total automaticamente.
- Impedir adicionar quantidade maior que o estoque disponível.

---

## US02 — Finalização de pedido (checkout)

**Como** cliente,
**quero** finalizar meu pedido escolhendo pagamento e entrega,
**para** concluir a compra.

### Critérios de aceite
- Selecionar endereço de entrega cadastrado.
- Escolher forma de pagamento (cartão, boleto, pix).
- Gerar pedido a partir dos itens do carrinho.
- Dar baixa no estoque dos produtos comprados.
- Esvaziar o carrinho após confirmação.

---

## US03 — Cadastro e gestão de perfil
**Como** cliente,
**quero** criar e editar meu perfil,
**para** comprar e vender produtos na loja.

### Critérios de aceite
- Cadastro com nome, email, senha e endereço.
- Validar formato de email e tamanho mínimo de senha.
- Impedir cadastro com email já existente.
- Editar dados cadastrais.
- Excluir a própria conta.

---

## US04 — Busca e filtro de produtos
**Como** cliente,
**quero** buscar jogos, consoles e acessórios por plataforma, categoria e condição,
**para** encontrar o que procuro.

### Critérios de aceite
- Listar produtos disponíveis.
- Filtrar por plataforma (PS5, Xbox, Switch, PC).
- Filtrar por categoria (jogo, console, acessório).
- Filtrar por condição (novo/usado).
- Exibir produtos esgotados como indisponíveis.
## US05 — Histórico de pedidos

**Como** cliente,  
**quero** consultar meus pedidos anteriores,  
**para** acompanhar minhas compras.

### Critérios de aceite
- Listar todos os pedidos do cliente.
- Exibir o status do pedido (pendente, enviado, entregue, cancelado).
- Exibir os itens e valores de um pedido específico.
- Permitir o cancelamento do pedido caso ele ainda não tenha sido enviado.

---

## US06 — Venda de produto usado

**Como** cliente,  
**quero** cadastrar um jogo, console ou acessório usado para vender à loja,  
**para** receber uma oferta pelo produto.

### Critérios de aceite
- Informar o tipo de produto (jogo, console ou acessório).
- Informar a plataforma do produto.
- Informar o título ou nome do produto.
- Informar a condição do produto (novo/usado).
- Descrever o estado de conservação do item.
- Sugerir um preço de venda.
- Consultar o status da solicitação (em análise, aprovada, recusada).
- Visualizar o valor final ofertado pela loja.

