#!/bin/bash

# Проверяем, что образ существует
if [ ! -f "../build/armbian/output/images/boyjack-os-orange-pi.img" ]; then
    echo "Образ системы не найден!"
    exit 1
fi

# Указываем путь к устройству microSD (например, /dev/sdX)
echo "Введите путь к устройству (например, /dev/sdX):"
read DEVICE

# Записываем образ на microSD
echo "Запись образа на устройство $DEVICE..."
sudo dd if=../build/armbian/output/images/boyjack-os-orange-pi.img of=$DEVICE bs=4M status=progress

# Убедимся, что запись завершена
sudo sync

echo "Деплой завершен! Извлеките microSD и вставьте в ваше устройство."
