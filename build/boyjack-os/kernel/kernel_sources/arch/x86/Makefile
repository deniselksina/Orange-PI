# Makefile для сборки ядра для архитектуры x86

# Параметры сборки
ARCH = x86
CROSS_COMPILE = x86_64-linux-gnu-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
AS = $(CROSS_COMPILE)as
AR = $(CROSS_COMPILE)ar
STRIP = $(CROSS_COMPILE)strip

# Параметры пути к исходникам
KERNEL_SRC = $(PWD)/kernel_sources
OBJ_DIR = $(PWD)/build
BUILD_DIR = $(OBJ_DIR)/x86

# Параметры исходников ядра
SRC = $(KERNEL_SRC)/kernel/ init.c irq.c timers.c memory.c intel.c amd.c
SRC_C = $(wildcard $(SRC) *.c)
SRC_ASM = $(wildcard $(KERNEL_SRC)/arch/x86/*.S)

# Флаги компиляции
CFLAGS = -Wall -Wextra -O2 -m64 -ffreestanding -fno-builtin -nostdlib -I$(KERNEL_SRC)/include
LDFLAGS = -T$(KERNEL_SRC)/arch/x86/linker.ld -m elf_x86_64 -nostdlib -lgcc
ASFLAGS = -m64

# Сборка ядра
all: $(BUILD_DIR)/vmlinuz

# Компиляция исходников C
$(BUILD_DIR)/%.o: $(KERNEL_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция исходников ассемблера
$(BUILD_DIR)/%.o: $(KERNEL_SRC)/arch/x86/%.S
	$(AS) $(ASFLAGS) $< -o $@

# Сборка ядра
$(BUILD_DIR)/vmlinuz: $(SRC_C) $(SRC_ASM)
	$(CC) $(CFLAGS) $(SRC_C) $(SRC_ASM) -o $(BUILD_DIR)/vmlinuz $(LDFLAGS)

# Очистка промежуточных файлов
clean:
	rm -rf $(BUILD_DIR)/*

# Установка ядра
install: $(BUILD_DIR)/vmlinuz
	cp $(BUILD_DIR)/vmlinuz /boot/vmlinuz-x86

# Печать информации о сборке
info:
	@echo "Сборка ядра для архитектуры x86"
	@echo "Используемая версия компилятора: $(CC)"
	@echo "Пути к исходным файлам: $(KERNEL_SRC)"

.PHONY: all clean install info
