# ====================================================================================
# MAKEFILE - PROJETO GRAFOS
# ====================================================================================

# 'CC' define o compilador
CC = gcc

# 'CFLAGS' guarda as opções de compilação
# -Wall e -Wextra ativam avisos; -O2 otimiza; -g gera símbolos de depuração.
# -I. procura os headers na pasta atual.
CFLAGS = -Wall -O2 -Wextra -g -I.

# 'LIBS' define bibliotecas externas necessárias na etapa de linkedição.
LIBS =

# //ADICIONADO: identifica Windows pelo ambiente do Make ou pela variável windir.
# Isso permite escolher nomes de executável e comandos compatíveis com cada sistema.
ifeq ($(OS),Windows_NT)
    IS_WINDOWS := 1
else ifneq ($(windir),)
    IS_WINDOWS := 1
endif

# //ADICIONADO: comandos de diretório, limpeza e execução variam entre Windows e Linux.
ifeq ($(IS_WINDOWS),1)
    OUT = grafo_exe.exe
    # //ADICIONADO: objetos separados evitam reutilizar .o de uma compilação Linux.
    OBJDIR = obj/windows
    EXEC = ./$(OUT)
    DELETE = if exist $(OUT) del /f /q $(OUT)
    RMDIR = if exist obj rmdir /s /q obj
    MKDIR = if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
    CLEAR =
    RUN_EXT = start "" "$(OUT)"
else
    OUT = ./grafo_exe
    # //ADICIONADO: objetos separados evitam reutilizar .o de uma compilação Windows.
    OBJDIR = obj/linux
    EXEC = $(OUT)
    DELETE = rm -f $(OUT)
    RMDIR = rm -rf obj
    MKDIR = mkdir -p $(dir $@)
    CLEAR = && clear
    RUN_EXT = gnome-terminal -- $(OUT)
endif

# ------------------------------------------------------------------------------------
# FONTES E ARQUIVOS OBJETO
# ------------------------------------------------------------------------------------

# Compila os .c da pasta atual.
SRC = $(wildcard *.c)

# 'OBJDIR' guarda os .o em uma pasta própria para o sistema operacional atual.

# //ADICIONADO: inclui os objetos das fontes dentro de "Kn, Cn e Nulos".
# Os nomes dos objetos não têm espaços para simplificar a compilação no Windows.
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC)) \
      $(OBJDIR)/Kn_Cn_e_Nulos_criar_ciclo.o \
      $(OBJDIR)/Kn_Cn_e_Nulos_criar_grafo_completo.o \
      $(OBJDIR)/Kn_Cn_e_Nulos_nulificar_grafo.o

# ====================================================================================
# REGRAS DE COMPILAÇÃO
# ====================================================================================

# Alvo principal: 'make' compila o executável.
all: $(OUT)

# Liga todos os objetos para gerar o executável.
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

# Compila fontes da pasta atual para obj/.
$(OBJDIR)/%.o: %.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c "$<" -o "$@"

# //ADICIONADO: regra especial para compilar fontes cujo caminho contém espaços.
$(OBJDIR)/Kn_Cn_e_Nulos_%.o: Kn,\ Cn\ e\ Nulos/%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c "$<" -o "$@"

# //ADICIONADO: no Linux, debug usa Valgrind; no Windows, usa GDB, que é a opção
# de depuração compatível com as ferramentas GCC normalmente usadas nesse sistema.
ifeq ($(IS_WINDOWS),1)
debug: $(OUT)
	gdb $(OUT)
else
debug: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(OUT)
endif

# Executa o programa no terminal atual.
run: $(OUT)
	$(EXEC)

# Abre o programa em uma nova janela de terminal.
run-ext: $(OUT)
	$(RUN_EXT)

# Remove os arquivos de compilação e o executável.
clean:
	$(RMDIR)
	$(DELETE) $(CLEAR)

.PHONY: all debug run run-ext clean
