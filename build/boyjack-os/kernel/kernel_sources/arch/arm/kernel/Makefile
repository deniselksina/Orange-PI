# Makefile для сборки ядра ARM

# Установки
KERNEL_SRC = $(PWD)/kernel_sources
ARCH = arm
CROSS_COMPILE = arm-linux-gnueabihf-

# Определяем файлы исходников и конфигурации
CONFIG = $(KERNEL_SRC)/kernel/.config
PATCHES = $(KERNEL_SRC)/kernel/patches
BUILD_DIR = $(PWD)/build
OUTPUT_DIR = $(PWD)/output

# Флаги компилятора
CFLAGS = -O2 -g
LDFLAGS = -T $(KERNEL_SRC)/arch/arm/boot/compressed/vmlinux.lds

# Основные цели
all: kernel

kernel: $(CONFIG)
	@echo "Начинаем сборку ядра ARM..."
	@mkdir -p $(BUILD_DIR)
	@cd $(KERNEL_SRC)/kernel && make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) O=$(BUILD_DIR) all

# Генерация конфигурации
$(CONFIG):
	@echo "Генерация конфигурации ядра..."
	@cp $(KERNEL_SRC)/kernel/configs/defconfig $(CONFIG)
	@cd $(KERNEL_SRC)/kernel && make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) O=$(BUILD_DIR) oldconfig

# Применение патчей
patch:
	@echo "Применение патчей..."
	@for patch in $(PATCHES)/*.patch; do \
		patch -p1 < $$patch; \
	done

# Сборка образа ядра
image: kernel
	@echo "Создание образа ядра..."
	@cd $(KERNEL_SRC)/kernel && make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) O=$(BUILD_DIR) zImage

# Сборка модуля ядра
modules: kernel
	@echo "Сборка модулей ядра..."
	@cd $(KERNEL_SRC)/kernel && make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) O=$(BUILD_DIR) modules

# Установка модулей
install-modules:
	@echo "Установка модулей ядра..."
	@cd $(KERNEL_SRC)/kernel && make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) O=$(BUILD_DIR) INSTALL_MOD_PATH=$(OUTPUT_DIR)/modules modules_install

# Очистка файлов сборки
clean:
	@echo "Очистка..."
	@rm -rf $(BUILD_DIR) $(OUTPUT_DIR)

# Установка в образ
install: image
	@echo "Установка ядра в выходной каталог..."
	@mkdir -p $(OUTPUT_DIR)/boot
	@cp $(BUILD_DIR)/arch/arm/boot/zImage $(OUTPUT_DIR)/boot/
	@cp $(BUILD_DIR)/System.map $(OUTPUT_DIR)/boot/

# Установка конфигурации
install-config:
	@cp $(CONFIG) $(OUTPUT_DIR)/boot/

.PHONY: all kernel patch image modules install install-modules clean install-config
