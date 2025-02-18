#!/bin/bash

# Переключаемся в папку с исходниками
cd ../build/armbian

# Убираем старые сборки
echo "Очистка старых сборок..."
make clean

# Конфигурируем сборку
echo "Конфигурирование сборки..."
make sunxi_defconfig

# Старт сборки
echo "Сборка ядра и загрузчика..."
make -j$(nproc) uImage

# Собираем систему
echo "Сборка rootfs..."
make rootfs

echo "Сборка завершена!"
