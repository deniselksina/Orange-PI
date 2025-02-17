#!/bin/bash

# Проверка на наличие исходников U-Boot
if [ ! -d "$HOME/armbian-sources/u-boot" ]; then
  echo "Исходники U-Boot не найдены! Пожалуйста, сначала запустите download_sources.sh."
  exit 1
fi

cd $HOME/armbian-sources/u-boot

# Настройка конфигурации U-Boot для Orange PI
echo "Настройка конфигурации U-Boot..."
make orangepi_config

# Сборка U-Boot
echo "Сборка U-Boot..."
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j$(nproc)

echo "Сборка U-Boot завершена."
