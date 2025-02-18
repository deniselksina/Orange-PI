# Параметры для сборки
ARCH = arm
CROSS_COMPILE = arm-linux-gnueabihf-
KERNEL_DIR = $(CURDIR)/kernel_sources
OUT_DIR = $(CURDIR)/output
TARGET = zImage

# Определяем флаги для разных архитектур ARM
ARMV7_FLAGS = -mcpu=cortex-a7 -mfpu=vfpv4 -mfloat-abi=hard
ARMV8_FLAGS = -mcpu=cortex-a53 -mfpu=neon -mfloat-abi=hard
CORTEX_A72_FLAGS = -mcpu=cortex-a72 -mfpu=neon -mfloat-abi=hard

# Определяем флаги компиляции в зависимости от выбранной архитектуры
ifdef ARCHITECTURE
    ifeq ($(ARCHITECTURE), armv7)
        CFLAGS += $(ARMV7_FLAGS)
    endif
    ifeq ($(ARCHITECTURE), armv8)
        CFLAGS += $(ARMV8_FLAGS)
    endif
    ifeq ($(ARCHITECTURE), cortex-a72)
        CFLAGS += $(CORTEX_A72_FLAGS)
    endif
else
    $(error "ARCHITECTURE is not specified. Please define ARCHITECTURE variable.")
endif

# Определяем пути к исходным файлам и директориям
SRC_DIRS = $(KERNEL_DIR)/drivers $(KERNEL_DIR)/arch/$(ARCH)/cpu
OBJ_DIR = $(OUT_DIR)/obj

# Цель для сборки ядра
all: $(OUT_DIR)/$(TARGET)

# Сборка ядра
$(OUT_DIR)/$(TARGET): $(OBJ_DIR)/kernel.o
	$(CROSS_COMPILE)ld -o $@ $^ -T $(KERNEL_DIR)/arch/$(ARCH)/boot/linker.ld
	@echo "Kernel Image built successfully: $(OUT_DIR)/$(TARGET)"

# Компиляция исходников в объектные файлы
$(OBJ_DIR)/%.o: $(KERNEL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CROSS_COMPILE)gcc -c $< -o $@ $(CFLAGS)

# Очистка собранных файлов
clean:
	rm -rf $(OUT_DIR)
	rm -rf $(OBJ_DIR)

# Установка ядра в /boot
install: $(OUT_DIR)/$(TARGET)
	@echo "Installing kernel to /boot"
	cp $(OUT_DIR)/$(TARGET) /boot/

# Сборка Device Tree Blob (DTB)
dtb: 
	$(CROSS_COMPILE)dtc -I dts -O dtb -o $(OUT_DIR)/$(TARGET).dtb $(KERNEL_DIR)/arch/$(ARCH)/boot/dts/device.dts

.PHONY: all clean install dtb
