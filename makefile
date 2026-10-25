CC = gcc
CFLAGS = -O2 -g -I.
LIBS = 

OUT = /tmp/game
DELETE = rm -f
CLEAR = && clear

# Nome da pasta atualizado sem espaços
SRC = $(wildcard *.c) \
    $(wildcard Kn_Cne_Nulos/*.c)

# Gera a lista de arquivos .o a partir do SRC
OBJ = $(SRC:.c=.o)

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(OUT)

run: $(OUT)
	$(OUT)

run-ext: $(OUT)
	gnome-terminal -- $(OUT)

clean:
	$(DELETE) $(OUT) $(OBJ) $(CLEAR)