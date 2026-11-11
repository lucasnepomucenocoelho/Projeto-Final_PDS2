#ifndef JOGO_HPP
#define JOGO_HPP

#include "Produto.hpp"
#include <string>

/**
 * @class Jogo
 * @brief Representa um jogo eletrônico vendido na loja.
 * Herda de Produto e adiciona atributos específicos de jogos.
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
     * @throws std::invalid_argument se gênero ou classificação forem vazios.
     */
    Jogo(const std::string& titulo, const std::string& plataforma,
         double preco, Condicao condicao, int quantidadeEstoque,
         const std::string& genero, const std::string& classificacaoIndicativa);

    /**
     * @brief Retorna a categoria "Jogo".
     */
    std::string getCategoria() const override;

    /**
     * @brief Monta a descrição detalhada do jogo com todos os seus atributos.
     */
    std::string getDescricaoDetalhada() const override;

    /**
     * @brief Retorna o gênero do jogo.
     */
    std::string getGenero() const;

private:
    std::string genero_;
    std::string classificacaoIndicativa_;
};

#endif // JOGO_HPP
