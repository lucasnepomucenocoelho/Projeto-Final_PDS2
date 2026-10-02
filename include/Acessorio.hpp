#ifndef ACESSORIO_HPP
#define ACESSORIO_HPP

#include "Produto.hpp"
#include <string>

/**
 * @class Acessorio
 * @brief Representa um acessório para video game (controle, headset, etc.).
 */
class Acessorio : public Produto {
public:
    /**
     * @brief Construtor da classe Acessorio.
     * @param titulo Nome/título do produto.
     * @param plataforma Plataforma associada (ex.: PS5, Xbox, PC, Switch).
     * @param preco Preço de venda.
     * @param condicao Condição do produto (novo ou usado).
     * @param quantidadeEstoque Quantidade inicial em estoque.
     * @param tipo Tipo do acessório (ex.: controle, headset, volante).
     * @param compativelCom Plataformas compatíveis, separadas por vírgula.
     */
    Acessorio(const std::string& titulo, const std::string& plataforma,
              double preco, Condicao condicao, int quantidadeEstoque,
              const std::string& tipo, const std::string& compativelCom);

    std::string getCategoria() const override;
    std::string getDescricaoDetalhada() const override;

    std::string getTipo() const;

private:
    std::string tipo_;
    std::string compativelCom_;
};

#endif // ACESSORIO_HPP
