#!/bin/bash

# Настройка U-Boot для Orange PI

# Путь к исходникам U-Boot
UBOOT_DIR="./u-boot"

# Настройка переменных для Orange PI
BOARD="orangepi_pc"
UBOOT_CONFIG="orangepi_pc_defconfig"

# Функция для конфигурации и сборки U-Boot
configure_uboot() {
    echo "Настройка и сборка U-Boot для $BOARD"
    cd $UBOOT_DIR
    make distclean
    make $UBOOT_CONFIG
    make -j4
}

# Установка U-Boot на устройство
install_uboot() {
    echo "Установка U-Boot на устройство"
    sudo dd if=u-boot.img of=/dev/sdX bs=1M seek=8
}

# Запуск процесса конфигурации и установки U-Boot
configure_uboot
install_uboot
