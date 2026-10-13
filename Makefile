# ============================================================
# Makefile - Projeto Final PDS2 (E-commerce de Video Games)
# ============================================================

CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I include -I tests
CXXFLAGS += -DDOCTEST_CONFIG_NO_MULTITHREADING


# Fontes da aplicacao (exclui main.cpp para nao conflitar com o main do doctest)
SRC      := $(filter-out src/main.cpp, $(wildcard src/*.cpp))
MAIN     := src/main.cpp

# Fontes dos testes
TEST_SRC := $(wildcard tests/*.cpp)
TEST_BIN := build/testes
APP_BIN  := build/app

# ============================================================
# Alvos principais
# ============================================================

all: $(APP_BIN)

$(APP_BIN): $(SRC) $(MAIN)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $^ -o $@

run: all
	./$(APP_BIN)

# ============================================================
# Testes
# ============================================================

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(SRC) $(TEST_SRC)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $^ -o $@

# ============================================================
# Cobertura (opcional, exige gcovr instalado)
# ============================================================

coverage: clean
	@mkdir -p build
	$(CXX) $(CXXFLAGS) --coverage -O0 -g $(SRC) $(TEST_SRC) -o build/testes_cov
	-./build/testes_cov || true
	gcovr -r . --html --html-details -o build/coverage.html
	@echo "Relatorio: build/coverage.html"

# ============================================================
# Limpeza
# ============================================================

clean:
	rm -rf build
	rm -f *.gcda *.gcno *.gcov
	rm -f src/*.gcda src/*.gcno src/*.gcov
	rm -f tests/*.gcda tests/*.gcno tests/*.gcov

.PHONY: all run test coverage clean
