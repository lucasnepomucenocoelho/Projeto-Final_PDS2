#ifndef PERSISTENCIA_HPP
#define PERSISTENCIA_HPP

#include "Estoque.hpp"
#include <string>

class Persistencia {
public:
    static void salvar(const Estoque& estoque, const std::string& nomeArquivo);
    static void carregar(Estoque& estoque, const std::string& nomeArquivo);
};

#endif