#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Produto.hpp"
#include <string>

/**
 * @class Console
 * @brief Representa um console de video game vendido na loja.
 */
class Console : public Produto {
public:
    /**
     * @brief Construtor da classe Console.
     * @param titulo Nome/título do produto.
     * @param plataforma Plataforma associada (ex.: PS5, Xbox, PC, Switch).
     * @param preco Preço de venda.
     * @param condicao Condição do produto (novo ou usado).
     * @param quantidadeEstoque Quantidade inicial em estoque.
     * @param capacidadeArmazenamento Capacidade de armazenamento em GB.
     * @param acompanhaControle Indica se acompanha ao menos um controle.
     */
    Console(const std::string& titulo, const std::string& plataforma,
            double preco, Condicao condicao, int quantidadeEstoque,
            int capacidadeArmazenamento, bool acompanhaControle);

    std::string getCategoria() const override;
    std::string getDescricaoDetalhada() const override;

    int getCapacidadeArmazenamento() const;

private:
    int capacidadeArmazenamento_;
    bool acompanhaControle_;
};

#endif // CONSOLE_HPP
