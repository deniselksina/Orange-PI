#!/bin/bash

# Настройка для Orange PI
BOARD="orangepi"
KERNEL_CONFIG="orangepi_defconfig"
DISTRO="ubuntu"
RELEASE="focal"
ARCH="arm"

# Обновление системы
sudo apt update
sudo apt upgrade -y

# Установка необходимых пакетов
sudo apt install gcc-arm-linux-gnueabihf build-essential u-boot-tools

# Настройка компиляции
export CROSS_COMPILE="arm-linux-gnueabihf-"
export KERNEL_SRC="/path/to/kernel/source"
export ROOTFS="/path/to/rootfs"

# Компиляция ядра
cd $KERNEL_SRC
make $KERNEL_CONFIG
make -j$(nproc)

# Сборка rootfs
cd $ROOTFS
# Дополнительные команды для настройки rootfs
