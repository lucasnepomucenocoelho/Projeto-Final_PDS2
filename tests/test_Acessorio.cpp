#include "doctest.h"
#include "Acessorio.hpp"

TEST_CASE("Acessorio - getCategoria e getTipo (polimorfismo)") {
    Acessorio controle("DualSense", "PS5", 499.90, Condicao::NOVO, 10,
                        "Controle", "PS5");

    CHECK(controle.getCategoria() == "Acessorio");
    CHECK(controle.getTipo() == "Controle");
}
