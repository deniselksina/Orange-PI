# Makefile для сборки специфичных инструкций и оптимизаций для ARMv8

# Установите путь к инструментам кросс-компиляции для ARMv8
CC = aarch64-linux-gnu-gcc
CFLAGS = -Wall -O3 -mcpu=cortex-a53 -march=armv8-a -mfpu=neon-fp-armv8
LDFLAGS = 

# Исходные файлы
SRC = instructions.c optimizations.c
OBJ = $(SRC:.c=.o)
EXEC = armv8_example

# Правила сборки
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка промежуточных файлов
clean:
	rm -f $(OBJ) $(EXEC)

# Установка
install: $(EXEC)
	# Установите программу в нужное место
	install -m 755 $(EXEC) /usr/local/bin/

# Тестирование программы
test: $(EXEC)
	./$(EXEC)
