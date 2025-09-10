# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -g -I.

# Arquivos fonte
SRCS = main.c \
       algoritimo/floyd-warshall.c \
       cadastro/cadastro-manual.c \
       cadastro/carregar-cidades.c \
       cadastro/primeiro-acesso.c \
       dados/util.c \
       dados/memoria.c \
       exibicao/exibir-matrizes.c \
       exibicao/menu-cadastro-cidades.c \
       exibicao/menu-exibir-matrizes.c \
       exibicao/menu-principal.c \
       exibicao/menu-salvar.c \
       menor-caminho/calcular-rota.c \
       menor-caminho/reconstruir-caminho.c \
       salvamento/salvar-dados-iniciais.c \
       salvamento/salvar-resultados.c

# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Nome do executável
TARGET = rotas

# Regra padrão
all: $(TARGET)

# Regra para linkar os arquivos objeto
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar os arquivos fonte em arquivos objeto
%.o: %.c prototipos.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Arquivos de teste
TEST_SRCS = testes/teste_main.c testes/teste_util.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_TARGET = testes/teste_run

# Regra para compilar e rodar os testes
test: $(TEST_TARGET)
	./$(TEST_TARGET) || true

$(TEST_TARGET): $(TEST_SRCS) $(filter-out main.o,$(OBJS))
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRCS) $(filter-out main.o,$(OBJS))

# Phony targets
.PHONY: all clean test
