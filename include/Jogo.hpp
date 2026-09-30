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
