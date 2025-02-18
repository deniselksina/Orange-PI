# Makefile для сборки ядра x86

# Переменные
ARCH = x86
KERNEL_DIR = $(PWD)
SRC_DIR = $(KERNEL_DIR)/src
OBJ_DIR = $(KERNEL_DIR)/obj
BIN_DIR = $(KERNEL_DIR)/bin
OUTPUT = $(BIN_DIR)/vmlinuz

CC = gcc
LD = ld
AS = nasm
CFLAGS = -m32 -ffreestanding -nostdlib -O2 -Wall -Wextra
LDFLAGS = -m elf_i386 -T link.ld
ASFLAGS = -f elf32

# Пути к исходным файлам и заголовкам
INCLUDE_DIRS = -I$(KERNEL_DIR)/include
SRC_FILES = $(SRC_DIR)/*.c $(SRC_DIR)/arch/x86/*.c $(SRC_DIR)/drivers/*.c $(SRC_DIR)/kernel/*.c

# Объектные файлы
OBJ_FILES = $(SRC_FILES:.c=.o)

# Правила сборки

# Главная цель: сборка ядра
all: $(OUTPUT)

$(OUTPUT): $(OBJ_FILES)
	@echo "Сборка ядра..."
	$(LD) $(OBJ_FILES) -o $(OUTPUT) $(LDFLAGS)
	@echo "Ядро собрано успешно!"

# Компиляция исходников в объектные файлы
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Компиляция $<..."
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Ассемблерные файлы
$(SRC_DIR)/%.o: $(SRC_DIR)/%.s
	@echo "Ассемблирование $<..."
	$(AS) $(ASFLAGS) $< -o $@

# Очистка промежуточных и объектных файлов
clean:
	@echo "Очистка..."
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*

# Установка ядра (копирование в /boot)
install: $(OUTPUT)
	cp $(OUTPUT) /boot/vmlinuz-x86

# Правило для создания директорий
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

.PHONY: all clean install
