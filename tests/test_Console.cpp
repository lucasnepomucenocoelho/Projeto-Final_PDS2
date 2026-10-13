#include "doctest.h"
#include "Console.hpp"

TEST_CASE("Console - getCategoria (polimorfismo)") {
    Console console("PlayStation 5", "PS5", 3999.90, Condicao::NOVO, 4, 825, true);
    CHECK(console.getCategoria() == "Console");
}

TEST_CASE("Console - getCapacidadeArmazenamento") {
    Console console("Xbox Series X", "Xbox", 4299.90, Condicao::NOVO, 2, 1000, true);
    CHECK(console.getCapacidadeArmazenamento() == 1000);
}
