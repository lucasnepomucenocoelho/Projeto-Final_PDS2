#include "Administrador.hpp"
#include <sstream>

Administrador::Administrador(const std::string& nome, const std::string& email,
                              const std::string& senha)
    : nome_(nome), email_(email), senha_(senha) {}

bool Administrador::autenticar(const std::string& email, const std::string& senha) const {
    return email_ == email && senha_ == senha;
}

void Administrador::cadastrarProduto(std::shared_ptr<Produto> produto, Estoque& estoque) {
    estoque.adicionarProduto(produto);
}

bool Administrador::removerProduto(std::shared_ptr<Produto> produto, Estoque& estoque) {
    return estoque.removerProduto(produto);
}

void Administrador::avaliarSolicitacao(SolicitacaoVenda& solicitacao, bool aprovar,
                                        double precoFinal, Estoque& estoque) {
    if (aprovar) {
        auto produto = solicitacao.aprovar(precoFinal);
        if (produto) estoque.adicionarProduto(produto);
    } else {
        solicitacao.recusar("Recusada pelo administrador");
    }
}

std::string Administrador::gerarRelatorioVendas(const std::vector<Pedido>& pedidos) const {
    double total = 0.0;
    for (const auto& p : pedidos) total += p.calcularTotal();
    std::ostringstream oss;
    oss << "Relatorio de Vendas\n"
        << "Total de pedidos: " << pedidos.size() << "\n"
        << "Faturamento total: R$ " << total;
    return oss.str();
}
