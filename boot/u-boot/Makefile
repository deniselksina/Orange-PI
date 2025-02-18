# Устанавливаем целевую платформу и пути
TARGET = orangepi_pc
CROSS_COMPILE = arm-linux-gnueabihf-
ARCH = arm
BOARD = sunxi

# Инструкции по сборке
all: u-boot.bin

u-boot.bin:
    $(MAKE) -C $(BOARD) CROSS_COMPILE=$(CROSS_COMPILE) ARCH=$(ARCH) $(TARGET)
