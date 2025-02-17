#!/bin/bash
# Скрипт для настройки U-Boot на Orange PI

# Установка переменных окружения
export PATH=$PATH:/usr/local/bin

# Копирование u-boot.bin на SD-карту
sudo cp ~/uboot/uboot/u-boot.bin /dev/sdX

# Перезагрузка устройства
sudo reboot
