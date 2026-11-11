#include "Cliente.hpp"

/**
 * @brief Construtor da classe Cliente.
 * @param nome Nome do cliente.
 * @param email Email de login.
 * @param senha Senha de acesso.
 * @param endereco Endereço de entrega padrão.
 */
Cliente::Cliente(const std::string& nome, const std::string& email,
                  const std::string& senha, const std::string& endereco)
    : nome_(nome), email_(email), senha_(senha), endereco_(endereco) {}

/**
 * @brief Valida o login do cliente.
 * @param email Email a ser verificado.
 * @param senha Senha a ser verificada.
 * @return true se as credenciais estiverem corretas.
 */
bool Cliente::autenticar(const std::string& email, const std::string& senha) const {
    return email_ == email && senha_ == senha;
}

/**
 * @brief Edita os dados do perfil do cliente.
 * @param nome Novo nome.
 * @param email Novo email.
 * @param endereco Novo endereço.
 */
void Cliente::editarPerfil(const std::string& nome, const std::string& email,
                            const std::string& endereco) {
    nome_ = nome;
    email_ = email;
    endereco_ = endereco;
}

/**
 * @brief Retorna o carrinho de compras do cliente.
 */
CarrinhoDeCompras& Cliente::getCarrinho() { return carrinho_; }

/**
 * @brief Finaliza o pedido a partir dos itens no carrinho.
 * Esvazia o carrinho e adiciona o pedido ao histórico.
 * @param enderecoEntrega Endereço de entrega.
 * @param pagamento Objeto de pagamento.
 * @return O Pedido criado.
 */
Pedido Cliente::finalizarPedido(const std::string& enderecoEntrega,
                                 const Pagamento& pagamento) {
    Pedido p(carrinho_.getItens(), enderecoEntrega, pagamento);
    historicoPedidos_.push_back(p);
    carrinho_.esvaziar();
    return p;
}

/**
 * @brief Retorna o histórico de pedidos do cliente.
 */
const std::vector<Pedido>& Cliente::getHistoricoPedidos() const {
    return historicoPedidos_;
}

/**
 * @brief Cria uma nova solicitação de venda de um produto usado.
 * @param descricaoProduto Descrição do produto.
 * @param precoSugerido Preço desejado pelo cliente.
 * @return A solicitação criada e adicionada à lista.
 */
SolicitacaoVenda Cliente::criarSolicitacaoVenda(const std::string& descricaoProduto,
                                                 double precoSugerido) {
    SolicitacaoVenda s(email_, descricaoProduto, precoSugerido);
    solicitacoesVenda_.push_back(s);
    return s;
}

const std::vector<SolicitacaoVenda>& Cliente::getSolicitacoesVenda() const {
    return solicitacoesVenda_;
}

std::string Cliente::getNome() const { return nome_; }
std::string Cliente::getEmail() const { return email_; }
