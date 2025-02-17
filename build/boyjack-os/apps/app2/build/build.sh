#!/bin/bash

# Установка зависимостей, если необходимо
echo "Устанавливаем зависимости..."
sudo apt-get update
sudo apt-get install -y build-essential libgtk-3-dev

# Сборка проекта
echo "Собираем проект..."
make clean  # Очищаем предыдущие сборки
make        # Собираем проект

# Проверка на успешность сборки
if [ -f app2.bin ]; then
    echo "Сборка завершена успешно!"
else
    echo "Ошибка сборки!"
fi
