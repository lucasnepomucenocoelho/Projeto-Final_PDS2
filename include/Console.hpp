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
