#!/bin/bash
# Скрипт для сборки U-Boot для Orange PI

# Установка необходимых пакетов
sudo apt-get update
sudo apt-get install -y build-essential gcc-arm-linux-gnueabihf libncurses5-dev

# Переход в каталог с исходниками U-Boot
cd ~/uboot/uboot

# Применение патчей, если необходимо
# git apply ~/uboot/patches/*.patch

# Настройка конфигурации
make orange-pi-pc_defconfig

# Сборка U-Boot
make

# Установка U-Boot на SD-карту
sudo dd if=u-boot.bin of=/dev/sdX bs=1024 seek=8
