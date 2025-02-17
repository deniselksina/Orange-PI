#!/bin/bash

# Устанавливаем необходимые зависимости для сборки Armbian
echo "Установка зависимостей для сборки..."
sudo apt update
sudo apt install -y gcc-arm-linux-gnueabihf build-essential libssl-dev bc bison flex libncurses5-dev

# Устанавливаем необходимые утилиты для работы с U-Boot
echo "Установка инструментов для работы с U-Boot..."
sudo apt install -y u-boot-tools

# Устанавливаем зависимости для сборки ядра
echo "Установка зависимостей для сборки ядра..."
sudo apt install -y libssl-dev libncurses5-dev libelf-dev

# Завершаем подготовку
echo "Подготовка системы завершена."
