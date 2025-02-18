#!/bin/bash

# Обновляем систему и устанавливаем необходимые пакеты
echo "Установка зависимостей..."
sudo apt-get update
sudo apt-get install -y build-essential gcc-arm-linux-gnueabihf libncurses5-dev bc bison flex libssl-dev libelf-dev git

# Клонируем репозитории, если они еще не скачаны
if [ ! -d "../build/armbian" ]; then
    echo "Клонирование репозитория Armbian..."
    git clone https://github.com/armbian/build ../build/armbian
fi

# Проверяем, что установлены все необходимые зависимости
echo "Проверка зависимостей..."
dpkg -l | grep -E 'build-essential|gcc|libssl'

echo "Настройка завершена!"
