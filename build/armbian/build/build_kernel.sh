#!/bin/bash

# Проверка на наличие нужных исходников
if [ ! -d "$HOME/armbian-sources/linux" ]; then
  echo "Исходники ядра не найдены! Пожалуйста, сначала запустите download_sources.sh."
  exit 1
fi

cd $HOME/armbian-sources/linux

# Настройка конфигурации ядра для Orange PI
echo "Настройка конфигурации ядра..."
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- orangepi_defconfig

# Сборка ядра
echo "Сборка ядра..."
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j$(nproc)

echo "Сборка ядра завершена."
