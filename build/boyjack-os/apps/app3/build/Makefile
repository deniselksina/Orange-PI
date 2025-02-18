CC = gcc                    # Компилятор C
CFLAGS = -Wall -Wextra -O2   # Флаги компиляции (безопасность, оптимизация)
LDFLAGS =                    # Флаги линковки

SRC_DIR = ../src             # Папка с исходными файлами
BUILD_DIR = ./build          # Папка для сборки
EXEC = app3.bin              # Исполняемый файл

SRC = $(wildcard $(SRC_DIR)/*.c)    # Все исходники
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)  # Все объектные файлы

# Правило по умолчанию для сборки приложения
all: $(EXEC)

# Линковка объектных файлов в исполняемый файл
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Компиляция исходников в объектные файлы
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка собранных файлов
clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)

.PHONY: all clean
