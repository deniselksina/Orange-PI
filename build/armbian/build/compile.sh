#!/bin/bash

# Проверка на наличие необходимых прав
if [ "$(id -u)" -ne 0 ]; then
  echo "Для запуска этого скрипта нужны права суперпользователя!"
  exit 1
fi

# Определение путей и переменных
export BOARD="orangepi"
export ARCH="arm"
export DISTRO="ubuntu"
export RELEASE="focal"
export KERNEL_VERSION="5.10"

# Запуск конфигурации для сборки
echo "Настройка сборки для Armbian на платформу Orange PI..."
./config.sh

# Сборка системы
echo "Начинаю сборку системы..."
make -j$(nproc)

# Проверка успешности сборки
if [ $? -eq 0 ]; then
  echo "Сборка завершена успешно!"
else
  echo "Произошла ошибка при сборке!"
  exit 1
fi

# Вывод информации по созданному образу
echo "Готовый образ Armbian для Orange PI: $(pwd)/output/$BOARD-$RELEASE.img"
