#!/bin/bash

# Проверяем, что образ системы собран успешно
if [ -f "../build/armbian/output/images/boyjack-os-orange-pi.img" ]; then
    echo "Образ системы собран успешно!"
else
    echo "Ошибка сборки!"
    exit 1
fi

# Монтируем образ и проверяем содержимое
echo "Монтирование образа..."
sudo mount -o loop ../build/armbian/output/images/boyjack-os-orange-pi.img /mnt

# Проверяем важные конфигурационные файлы
if [ -f "/mnt/etc/fstab" ]; then
    echo "Файл fstab найден."
else
    echo "Ошибка: файл fstab не найден."
    exit 1
fi

if [ -f "/mnt/etc/network/interfaces" ]; then
    echo "Сетевые настройки найдены."
else
    echo "Ошибка: настройки сети не найдены."
    exit 1
fi

# Размонтируем образ после проверки
sudo umount /mnt

echo "Тестирование завершено!"
