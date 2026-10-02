#ifndef JOGO_HPP
#define JOGO_HPP

#include "Produto.hpp"
#include <string>

/**
 * @class Jogo
 * @brief Representa um jogo eletrônico vendido na loja.
 */
class Jogo : public Produto {
public:
    /**
     * @brief Construtor da classe Jogo.
     * @param titulo Nome/título do produto.
     * @param plataforma Plataforma associada (ex.: PS5, Xbox, PC, Switch).
     * @param preco Preço de venda.
     * @param condicao Condição do produto (novo ou usado).
     * @param quantidadeEstoque Quantidade inicial em estoque.
     * @param genero Gênero do jogo (ex.: RPG, ação, esporte).
     * @param classificacaoIndicativa Classificação etária (ex.: "L", "12", "18").
     */
    Jogo(const std::string& titulo, const std::string& plataforma,
         double preco, Condicao condicao, int quantidadeEstoque,
         const std::string& genero, const std::string& classificacaoIndicativa);

    std::string getCategoria() const override;
    std::string getDescricaoDetalhada() const override;

    std::string getGenero() const;

private:
    std::string genero_;
    std::string classificacaoIndicativa_;
};

#endif // JOGO_HPP
