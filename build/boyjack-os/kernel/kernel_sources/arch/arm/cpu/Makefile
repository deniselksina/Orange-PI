# Устанавливаем переменные
ARCH = arm
CROSS_COMPILE = arm-linux-gnueabihf-
KERNEL_DIR = $(CURDIR)/kernel_sources
OUT_DIR = $(CURDIR)/output
DTB_DIR = $(KERNEL_DIR)/arch/$(ARCH)/boot/dts
TARGET = zImage

# Параметры для различных ARM архитектур
ARMV7_FLAGS = -mcpu=cortex-a7 -mfpu=vfpv4 -mfloat-abi=hard
ARMV8_FLAGS = -mcpu=cortex-a53 -mfpu=neon -mfloat-abi=hard
CORTEX_A72_FLAGS = -mcpu=cortex-a72 -mfpu=neon -mfloat-abi=hard

# Определение оптимизаций в зависимости от архитектуры
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
    $(error "ARCHITECTURE is not set. Please specify ARM architecture.")
endif

# Директории для исходников и файлов
SRC_DIRS = $(KERNEL_DIR)/drivers $(KERNEL_DIR)/arch/$(ARCH)/cpu
OBJ_DIR = $(OUT_DIR)/obj

# Сборка ядра
all: $(OUT_DIR)/$(TARGET)

# Правило для сборки ядра
$(OUT_DIR)/$(TARGET): $(OBJ_DIR)/kernel.o
	$(CROSS_COMPILE)ld -o $@ $^ -T $(KERNEL_DIR)/arch/$(ARCH)/boot/linker.ld
	@echo "Kernel Image is built successfully at $(OUT_DIR)/$(TARGET)"

# Правила для компиляции исходников ядра
$(OBJ_DIR)/%.o: $(KERNEL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CROSS_COMPILE)gcc -c $< -o $@ $(CFLAGS)

# Очистка
clean:
	rm -rf $(OUT_DIR)
	rm -rf $(OBJ_DIR)

# Установка
install: $(OUT_DIR)/$(TARGET)
	@echo "Installing kernel to /boot"
	cp $(OUT_DIR)/$(TARGET) /boot/

# Сборка Device Tree Blob (DTB)
dtb: 
	$(CROSS_COMPILE)dtc -I dts -O dtb -o $(OUT_DIR)/$(TARGET).dtb $(DTB_DIR)/device.dts

.PHONY: all clean install dtb
