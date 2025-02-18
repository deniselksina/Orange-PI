#!/bin/bash

# Переключаемся в папку с исходниками
cd ../build/armbian

# Очищаем старые сборки
echo "Очистка старых сборок..."
make clean

# Конфигурируем сборку для Orange Pi
echo "Конфигурирование сборки..."
make sunxi_defconfig

# Собираем ядро
echo "Сборка ядра..."
make -j$(nproc) uImage

# Собираем систему
echo "Сборка rootfs..."
make rootfs

# Собираем финальный образ системы
echo "Создание образа системы..."
make image

echo "Сборка завершена!"
