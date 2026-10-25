CC = gcc
CFLAGS = -std=c99 -w

SRC = $(wildcard *.c)

ifeq ($(OS),Windows_NT)
    EXEC = programa.exe
    CLEAN_CMD = cmd /c "del /F /Q $(EXEC) 2>nul"
else
    EXEC = programa
    CLEAN_CMD = rm -f $(EXEC)
endif

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

run: all
	./$(EXEC)

clean:
	$(CLEAN_CMD)