CC=gcc                   # Компилятор
CFLAGS=-Wall -std=c99    # Флаги компилятора (например, включение предупреждений и указание стандарта C)
SRC=../src/main.c        # Исходный файл
OBJ=$(SRC:.c=.o)         # Объектный файл
BIN=app1.bin             # Выходной бинарник

# Правила сборки
all: $(BIN)

$(BIN): $(OBJ)
    $(CC) $(OBJ) -o $(BIN)

$(OBJ): $(SRC)
    $(CC) $(CFLAGS) -c $(SRC)

clean:
    rm -f $(OBJ) $(BIN)  # Удаление объектных файлов и бинарника

run: $(BIN)
    ./$(BIN)              # Запуск скомпилированного бинарника
