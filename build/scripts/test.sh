#!/bin/bash

# Проверяем, что сборка прошла успешно
if [ -f "../build/armbian/output/images/boyjack-os-orange-pi.img" ]; then
    echo "Образ системы собран успешно!"
else
    echo "Ошибка сборки!"
    exit 1
fi

# Монтируем образ и проверяем содержимое
echo "Монтирование образа..."
sudo mount -o loop ../build/armbian/output/images/boyjack-os-orange-pi.img /mnt

# Проверяем файлы конфигурации
if [ -f "/mnt/etc/fstab" ]; then
    echo "Файл fstab найден."
else
    echo "Ошибка: файл fstab не найден."
    exit 1
fi

# Размонтируем образ после проверки
sudo umount /mnt

echo "Тестирование завершено!"
