#include "doctest.h"
#include "Console.hpp"

TEST_CASE("Console - construtor e atributos") {
    Console console("PS5", "PS5", 4500.0, Condicao::NOVO, 3, 825, true);
    CHECK(console.getTitulo() == "PS5");
    CHECK(console.getCapacidadeArmazenamento() == 825);
    CHECK(console.getCategoria() == "Console");
}

TEST_CASE("Console - descricao detalhada") {
    Console console("Xbox Series X", "Xbox", 4000.0, Condicao::USADO, 2, 1000, false);
    std::string desc = console.getDescricaoDetalhada();
    
    CHECK(desc.find("Xbox Series X") != std::string::npos);
    CHECK(desc.find("1000") != std::string::npos);
    CHECK(desc.find("Nao") != std::string::npos);
    CHECK(desc.find("Usado") != std::string::npos);
}
