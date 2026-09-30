#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

/**
 * @brief Condição de conservação de um produto.
 */
enum class Condicao { NOVO, USADO };

/**
 * @class Produto
 * @brief Classe abstrata que representa um produto vendido na loja
 * (jogo, console ou acessório). Define o contrato comum e serve de
 * base para as classes concretas via herança/polimorfismo.
 */
class Produto {
public:
    /**
     * @brief Construtor da classe Produto.
     * @param titulo Nome/título do produto.
     * @param plataforma Plataforma associada (ex.: PS5, Xbox, PC, Switch).
     * @param preco Preço de venda.
     * @param condicao Condição do produto (novo ou usado).
     * @param quantidadeEstoque Quantidade inicial em estoque.
     */
    Produto(const std::string& titulo, const std::string& plataforma,
            double preco, Condicao condicao, int quantidadeEstoque);

    virtual ~Produto() = default;

    /**
     * @brief Verifica se há quantidade suficiente em estoque.
     * @param quantidade Quantidade desejada.
     * @return true se disponível, false caso contrário.
     */
    bool verificarDisponibilidade(int quantidade) const;

    /**
     * @brief Informa se o produto está esgotado.
     */
    bool estaEsgotado() const;

    /**
     * @brief Atualiza o preço do produto.
     */
    void atualizarPreco(double novoPreco);

    /**
     * @brief Retorna a categoria do produto (ex.: "Jogo", "Console", "Acessorio").
     * Método puro, implementado por cada subclasse.
     */
    virtual std::string getCategoria() const = 0;

    /**
     * @brief Retorna uma descrição detalhada, incluindo atributos
     * específicos da subclasse.
     */
    virtual std::string getDescricaoDetalhada() const = 0;

    std::string getTitulo() const;
    std::string getPlataforma() const;
    double getPreco() const;
    Condicao getCondicao() const;
    int getQuantidadeEstoque() const;
    void setQuantidadeEstoque(int quantidade);

protected:
    std::string titulo_;
    std::string plataforma_;
    double preco_;
    Condicao condicao_;
    int quantidadeEstoque_;
};

#endif // PRODUTO_HPP
