#!/bin/bash

# Установка переменных для конфигурации сборки
export BUILD_DIR=$(pwd)
export PATCHES_DIR="$BUILD_DIR/patches"
export UBOOT_DIR="$BUILD_DIR/boot"
export KERNEL_DIR="$BUILD_DIR/kernel"

# Параметры для конфигурации сборки
echo "Настройка сборки для Armbian..."

# Настройка загрузчика U-Boot для Orange PI
if [ ! -d "$UBOOT_DIR" ]; then
  echo "Загрузка исходников U-Boot..."
  git clone https://github.com/u-boot/u-boot.git $UBOOT_DIR
fi

# Настройка ядра Linux
if [ ! -d "$KERNEL_DIR" ]; then
  echo "Загрузка исходников ядра Linux..."
  git clone --branch $KERNEL_VERSION https://github.com/armbian/linux.git $KERNEL_DIR
fi

# Применение патчей (если есть)
if [ -d "$PATCHES_DIR" ]; then
  echo "Применение патчей..."
  for patch in $PATCHES_DIR/*.patch; do
    patch -p1 < $patch
  done
fi

echo "Конфигурация завершена. Готово к сборке."
