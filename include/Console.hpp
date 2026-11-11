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
     * @throws std::invalid_argument se a capacidade for menor ou igual a zero.
     */
    Console(const std::string& titulo, const std::string& plataforma,
            double preco, Condicao condicao, int quantidadeEstoque,
            int capacidadeArmazenamento, bool acompanhaControle);

    /**
     * @brief Retorna a categoria "Console".
     */
    std::string getCategoria() const override;

    /**
     * @brief Monta a descrição detalhada do console.
     */
    std::string getDescricaoDetalhada() const override;

    /**
     * @brief Retorna a capacidade de armazenamento em GB.
     */
    int getCapacidadeArmazenamento() const;

private:
    int capacidadeArmazenamento_;
    bool acompanhaControle_;
};

#endif // CONSOLE_HPP
