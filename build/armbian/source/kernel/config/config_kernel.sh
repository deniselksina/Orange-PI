#!/bin/bash

# Настройка конфигурации ядра для Orange PI
echo "Настройка конфигурации ядра для Orange PI..."
cp defconfig .config
make ARCH=arm orange-pi.config
make ARCH=arm menuconfig
