#!/bin/bash

# Убедимся, что в рабочем каталоге есть все необходимые директории
mkdir -p $HOME/armbian-sources

# Скачиваем исходники для Armbian
echo "Скачивание исходников для Armbian..."
git clone https://github.com/armbian/build.git $HOME/armbian-sources

# Скачиваем исходники ядра для Orange PI
echo "Скачивание исходников ядра Linux..."
git clone https://github.com/armbian/linux.git $HOME/armbian-sources/linux

# Скачиваем репозиторий для U-Boot
echo "Скачивание исходников U-Boot..."
git clone https://github.com/u-boot/u-boot.git $HOME/armbian-sources/u-boot

echo "Все исходники загружены."
