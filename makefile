# ====================================================================================
# MAKEFILE - PROJETO GRAFOS
# ====================================================================================

# 'CC' define o compilador
CC = gcc

# 'CFLAGS' guarda as opções de compilação
# -I. diz ao compilador para procurar o grafo.h na pasta atual
CFLAGS = -Wall -O2 -Wextra -g -I.

# 'LIBS' para bibliotecas externas. 
# Deixei vazio porque grafos normalmente não precisa do ncurses. 
# (Se um dia usar <math.h>, basta colocar -lm aqui)
LIBS = 

# 'OUT' é o nome e o caminho do executável final gerado
OUT = /tmp/grafo_exe

# Comandos do sistema
DELETE = rm -f
CLEAR = && clear

# ------------------------------------------------------------------------------------
# PASTAS E FICHEIROS
# ------------------------------------------------------------------------------------

# SRC pega todos os ficheiros .c da pasta principal e da subpasta dos nulos/completos
SRC = $(wildcard *.c) \
      $(wildcard Kn_Cne_Nulos/*.c)

# 'OBJDIR' é a pasta onde vamos guardar todos os ficheiros .o compilados
OBJDIR = obj

# Transformação automática: converte os .c do SRC para .o e redireciona para a pasta obj/
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

# ====================================================================================
# REGRAS DE COMPILAÇÃO
# ====================================================================================

# Alvo principal
all: $(OUT)

# Regra para gerar o executável final juntando todos os .o
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

# Regra para compilar cada .c num .o e guardar dentro da pasta obj/
# O @mkdir -p cria as subpastas automaticamente antes de compilar
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ------------------------------------------------------------------------------------
# COMANDOS EXTRAS (UTILITIES)
# ------------------------------------------------------------------------------------

# Corre o Valgrind para procurar fugas de memória (memory leaks)
debug: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(OUT)

# Corre o programa diretamente no terminal integrado
run: $(OUT)
	$(OUT)

# Abre uma nova janela preta do terminal do Ubuntu só com o programa
run-ext: $(OUT)
	gnome-terminal -- $(OUT)

# ALVO DE LIMPEZA
# Apaga a pasta 'obj' inteira (com o -r) e o executável final, limpando o projeto
clean:
	$(DELETE) -r $(OBJDIR)
	$(DELETE) $(OUT) $(CLEAR)