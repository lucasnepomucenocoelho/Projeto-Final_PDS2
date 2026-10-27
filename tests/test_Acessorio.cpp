#include "doctest.h"
#include "Acessorio.hpp"

TEST_CASE("Acessorio - construtor e atributos") {
    Acessorio ac("DualSense", "PS5", 400.0, Condicao::NOVO, 8, "Controle", "PS5, PC");
    CHECK(ac.getTitulo() == "DualSense");
    CHECK(ac.getTipo() == "Controle");
    CHECK(ac.getCategoria() == "Acessorio");
}

TEST_CASE("Acessorio - descricao detalhada") {
    Acessorio ac("Headset Gamer", "PC", 250.0, Condicao::USADO, 1, "Audio", "PC, PS4");
    std::string desc = ac.getDescricaoDetalhada();
    
    CHECK(desc.find("Headset Gamer") != std::string::npos);
    CHECK(desc.find("Audio") != std::string::npos);
    CHECK(desc.find("PC, PS4") != std::string::npos);
    CHECK(desc.find("Usado") != std::string::npos);
}

