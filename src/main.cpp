#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <limits>
#include <stdexcept>

#include "Estoque.hpp"
#include "Cliente.hpp"
#include "Jogo.hpp"
#include "Console.hpp"
#include "Acessorio.hpp"
#include "Pedido.hpp"
#include "Persistencia.hpp" // <--- Inclusão da persistência (Pedro)

void limparBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);
    Estoque estoque;

    // --- INÍCIO DA PARTE DO PEDRO (INTEGRANTE 4) ---
    // Carrega os dados do arquivo se existirem
    try {
        Persistencia::carregar(estoque, "catalogo.txt");
    } catch (const std::exception& e) {
        std::cerr << "Aviso ao carregar catalogo: " << e.what() << "\n";
    }

    // Se o estoque estiver vazio (primeira vez rodando), popula com produtos iniciais
    if (estoque.listarProdutos().empty()) {
        try {
            estoque.adicionarProduto(std::make_shared<Jogo>(
                "Elden Ring", "PS5", 250.0, Condicao::NOVO, 10, "RPG", "16"));
            estoque.adicionarProduto(std::make_shared<Console>(
                "PlayStation 5", "PS5", 4500.0, Condicao::NOVO, 3, 825, true));
            estoque.adicionarProduto(std::make_shared<Acessorio>(
                "Controle DualSense", "PS5", 400.0, Condicao::NOVO, 8, "Controle", "PS5, PC"));
            estoque.adicionarProduto(std::make_shared<Jogo>(
                "Zelda", "Switch", 350.0, Condicao::NOVO, 5, "Aventura", "L"));
        } catch (const std::exception& e) {
            std::cerr << "Erro ao inicializar catalogo: " << e.what() << "\n";
        }
    }
    // --- FIM DA PARTE DO PEDRO ---

    Cliente cliente("Pedro", "pedro@email.com", "senha123", "Rua A, 1");
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n=========================================\n";
        std::cout << "     LOJA DE VIDEO GAMES - MENU          \n";
        std::cout << "=========================================\n";
        std::cout << "1. Listar Catalogo\n";
        std::cout << "2. Adicionar ao Carrinho\n";
        std::cout << "3. Ver Carrinho e Total\n";
        std::cout << "4. Finalizar Pedido (Checkout)\n";
        std::cout << "5. Historico de Pedidos\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        
        // --- INÍCIO DA PARTE DO LUCAS (INTEGRANTE 3) ---
        try {
            std::cin >> opcao;
        } catch (const std::ios_base::failure& e) {
            std::cin.clear();
            limparBuffer();
            std::cout << "Erro: Digite apenas numeros!\n";
            continue;
        }
        // --- FIM DA PARTE DO LUCAS ---

        switch (opcao) {
            case 1: {
                std::cout << "\n--- CATALOGO ---\n";
                const auto& produtos = estoque.listarProdutos();
                for (size_t i = 0; i < produtos.size(); ++i) {
                    std::cout << "[" << i << "] " << produtos[i]->getDescricaoDetalhada() << "\n";
                }
                break;
            }
            case 2: {
                int idx, qtd;
                const auto& produtos = estoque.listarProdutos();
                
                std::cout << "Digite o indice do produto: ";
                try { std::cin >> idx; } 
                catch (...) { std::cin.clear(); limparBuffer(); std::cout << "Entrada invalida.\n"; break; }
                
                std::cout << "Digite a quantidade: ";
                try { std::cin >> qtd; } 
                catch (...) { std::cin.clear(); limparBuffer(); std::cout << "Entrada invalida.\n"; break; }

                if (idx < 0 || idx >= (int)produtos.size()) {
                    std::cout << "Indice invalido.\n";
                    break;
                }

                try {
                    if (cliente.getCarrinho().adicionarItem(produtos[idx], qtd)) {
                        std::cout << "Produto adicionado ao carrinho!\n";
                    } else {
                        std::cout << "Erro: Estoque insuficiente.\n";
                    }
                } catch (const std::invalid_argument& e) {
                    std::cout << "Erro de validacao: " << e.what() << "\n";
                }
                break;
            }
            case 3: {
                std::cout << "\n--- SEU CARRINHO ---\n";
                const auto& itens = cliente.getCarrinho().getItens();
                if (itens.empty()) {
                    std::cout << "Carrinho vazio.\n";
                } else {
                    for (const auto& item : itens) {
                        std::cout << "- " << item.produto->getTitulo() 
                                  << " (x" << item.quantidade << "): R$ " 
                                  << item.subtotal() << "\n";
                    }
                    std::cout << "TOTAL: R$ " << cliente.getCarrinho().calcularTotal() << "\n";
                }
                break;
            }
            case 4: {
                if (cliente.getCarrinho().getItens().empty()) {
                    std::cout << "Carrinho vazio. Adicione itens antes de finalizar.\n";
                    break;
                }
                
                double total = cliente.getCarrinho().calcularTotal();
                std::cout << "Total a pagar: R$ " << total << "\n";
                
                int formaInt;
                std::cout << "Forma de Pagamento (1-PIX, 2-CARTAO, 3-BOLETO): ";
                try { std::cin >> formaInt; } 
                catch (...) { std::cin.clear(); limparBuffer(); std::cout << "Entrada invalida.\n"; break; }
                
                FormaPagamento forma = FormaPagamento::PIX;
                if (formaInt == 2) forma = FormaPagamento::CARTAO;
                else if (formaInt == 3) forma = FormaPagamento::BOLETO;

                try {
                    Pagamento pg(total, forma);
                    Pedido pedido = cliente.finalizarPedido("Rua A, 1", pg);
                    
                    if (pedido.processarPagamento()) {
                        std::cout << "Pagamento APROVADO! Pedido realizado com sucesso.\n";
                    } else {
                        std::cout << "Pagamento PENDENTE/RECUSADO. Verifique sua forma de pagamento.\n";
                    }
                } catch (const std::exception& e) {
                    std::cout << "Erro no pagamento: " << e.what() << "\n";
                }
                break;
            }
            case 5: {
                std::cout << "\n--- HISTORICO ---\n";
                const auto& hist = cliente.getHistoricoPedidos();
                if (hist.empty()) {
                    std::cout << "Nenhum pedido realizado.\n";
                } else {
                    for (size_t i = 0; i < hist.size(); ++i) {
                        std::cout << "Pedido #" << i+1 << " - Total: R$ " << hist[i].calcularTotal() << "\n";
                    }
                }
                break;
            }
            case 0: {
                std::cout << "Salvando dados e saindo...\n";
                // --- INÍCIO DA PARTE DO PEDRO (SALVAR) ---
                try {
                    Persistencia::salvar(estoque, "catalogo.txt"); 
                } catch (const std::exception& e) {
                    std::cerr << "Erro ao salvar catalogo: " << e.what() << "\n";
                }
                // --- FIM DA PARTE DO PEDRO ---
                break;
            }
            default:
                std::cout << "Opcao invalida.\n";
        }
    }

    return 0;
}
