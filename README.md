# Projeto-Final_PDS2

E-commerce de compra e venda de produtos relacionados a video games (jogos, consoles e acessórios).

## Integrantes
- Guilherme Resende Scarpelli Cabral — guirscabral@ufmg.br
- Mateus Solis Resende Borges — mateussolis347@gmail.com
- Lucas Nepomuceno Coelho — lucasnepomuceno@ufmg.br
- Pedro Ruivo Valente Santiago Simplício — pruivovalentesantiagosimplicio@gmail.com

## Descrição do problema

O projeto consiste em um sistema de e-commerce voltado para a compra e venda de
produtos relacionados a video games — jogos, consoles e acessórios, tanto novos
quanto usados. Além do fluxo tradicional de compra (catálogo, carrinho e
checkout), a loja permite que clientes ofereçam seus próprios produtos usados
para venda, que passam por uma avaliação administrativa antes de entrarem no
catálogo.

## Objetivos principais

- Aplicar conceitos de Programação Orientada a Objetos (encapsulamento,
  herança e polimorfismo) na modelagem de produtos (Jogo, Console, Acessório)
  e demais entidades do domínio.
- Implementar um fluxo completo de e-commerce: cadastro, catálogo, carrinho,
  checkout, histórico de pedidos e pagamento.
- Implementar um fluxo de venda reversa (cliente → loja) via solicitações de
  venda avaliadas por um administrador.
- Garantir robustez por meio de testes unitários (doctest) e tratamento de
  exceções.

## Motivação

Escolhemos um domínio de e-commerce especializado em video games por ser um
mercado com forte presença de produtos usados (revenda de jogos, consoles e
acessórios), o que permite modelar não apenas o fluxo de compra tradicional,
mas também um fluxo de avaliação e revenda — enriquecendo a aplicação de
herança/polimorfismo (diferentes tipos de produto) e de regras de negócio
mais realistas.

## Estrutura do repositório

- `include/` — headers (.hpp) com os contratos das classes do sistema.
- `src/` — implementação (.cpp) das classes.
- `tests/` — testes unitários (doctest).
- `design/` — artefatos de modelagem (User Stories, Cartões CRC).
- `build/` — artefatos de compilação.
- `Doxyfile` — configuração para geração da documentação (Doxygen).
- `Makefile` — automação da compilação (`make`, `make run`).

## Principais classes

`Produto` (abstrata) → `Jogo`, `Console`, `Acessorio` · `CarrinhoDeCompras` ·
`Pedido` · `Pagamento` · `Estoque` · `SolicitacaoVenda` · `Cliente` ·
`Administrador`.

## Documentação

A documentação técnica das classes é gerada via Doxygen a partir dos
comentários nos headers:
```bash
doxygen Doxyfile
```
O resultado fica disponível em `docs/html/index.html`.
