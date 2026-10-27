#include "doctest.h"
#include "Cliente.hpp"
#include "Jogo.hpp"

TEST_CASE("Cliente - autenticar e editar") {
    Cliente c("Pedro", "pedro@email.com", "senha", "Rua A");
    CHECK(c.autenticar("pedro@email.com", "senha") == true);
    CHECK(c.autenticar("errado@email.com", "senha") == false);
    
    c.editarPerfil("Pedro S.", "novo@email.com", "Rua B");
    CHECK(c.getNome() == "Pedro S.");
    CHECK(c.getEmail() == "novo@email.com");
}

TEST_CASE("Cliente - pedidos e solicitacoes") {
    Cliente c("Pedro", "pedro@email.com", "senha", "Rua A");
    auto jogo = std::make_shared<Jogo>("Elden", "PS5", 100.0, Condicao::NOVO, 10, "RPG", "L");
    
    c.getCarrinho().adicionarItem(jogo, 2);
    Pagamento pg(200.0, FormaPagamento::PIX);
    
    Pedido p = c.finalizarPedido("Rua B", pg); // Cobre linha 26
    CHECK(p.calcularTotal() == doctest::Approx(200.0));
    CHECK(c.getHistoricoPedidos().size() == 1);
    CHECK(c.getCarrinho().getItens().empty()); 

    c.criarSolicitacaoVenda("PS4", 800.0); // Cobre linha 37
    CHECK(c.getSolicitacoesVenda().size() == 1);
}
