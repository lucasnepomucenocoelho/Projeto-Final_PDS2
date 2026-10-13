#include "Administrador.hpp"

Administrador::Administrador(const std::string& nome, const std::string& email,
                              const std::string& senha)
    : nome_(nome), email_(email), senha_(senha) {}

bool Administrador::autenticar(const std::string& email, const std::string& senha) const {
    // TODO (C8): comparar email/senha com email_/senha_.
    (void)email;
    (void)senha;
    return false;
}

void Administrador::cadastrarProduto(std::shared_ptr<Produto> produto, Estoque& estoque) {
    // TODO (C8): delegar para estoque.adicionarProduto(produto).
    (void)produto;
    (void)estoque;
}

bool Administrador::removerProduto(std::shared_ptr<Produto> produto, Estoque& estoque) {
    // TODO (C8): delegar para estoque.removerProduto(produto).
    (void)produto;
    (void)estoque;
    return false;
}

void Administrador::avaliarSolicitacao(SolicitacaoVenda& solicitacao, bool aprovar,
                                        double precoFinal, Estoque& estoque) {
    // TODO (C8): se aprovar, chamar solicitacao.aprovar(precoFinal) e
    // adicionar o produto resultante ao estoque; senao, solicitacao.recusar(...).
    (void)solicitacao;
    (void)aprovar;
    (void)precoFinal;
    (void)estoque;
}

std::string Administrador::gerarRelatorioVendas(const std::vector<Pedido>& pedidos) const {
    // TODO (C8): calcular total, produtos mais vendidos e ticket medio.
    (void)pedidos;
    return "";
}
