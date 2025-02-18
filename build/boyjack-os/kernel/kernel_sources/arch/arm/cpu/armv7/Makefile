# Установим переменные для компилятора и флагов
CC = arm-linux-gnueabihf-gcc
CFLAGS = -Wall -O2 -march=armv7-a -mfpu=vfpv3-d16 -mfloat-abi=hard -ftree-vectorize
LDFLAGS = -lm

# Папки с исходниками
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Источник файлов
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/armv7_program

# Правило по умолчанию
all: $(TARGET)

# Правило для создания целевого исполняемого файла
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET) $(LDFLAGS)

# Правило для компиляции исходников в объектные файлы
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для очистки сгенерированных файлов
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Правило для создания папок (если они не существуют)
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Правило для тестирования сборки
test:
	@echo "Test build for ARMv7 is complete."

.PHONY: all clean test
