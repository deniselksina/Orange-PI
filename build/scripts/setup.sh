#!/bin/bash

# Устанавливаем необходимые пакеты
echo "Установка зависимостей..."
sudo apt-get update
sudo apt-get install -y build-essential gcc-arm-linux-gnueabihf libncurses5-dev bc bison flex libssl-dev libelf-dev

# Клонируем репозитории, если они еще не скачаны
if [ ! -d "../build/armbian" ]; then
    echo "Клонирование репозитория Armbian..."
    git clone https://github.com/armbian/build ../build/armbian
fi

echo "Настройка завершена!"
