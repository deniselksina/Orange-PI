CC = gcc
CFLAGS = -Wall -g
LDFLAGS = `pkg-config --cflags --libs gtk+-3.0`
SRC = ../src/*.c
OBJ = $(SRC:.c=.o)
OUT = app2.bin

# Правило для сборки бинарника
$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(LDFLAGS)

# Правило для компиляции исходников в объектные файлы
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка скомпилированных файлов
clean:
	rm -f $(OBJ) $(OUT)
