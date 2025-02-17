#!/bin/bash

# Конфигурация ядра для Orange PI

# Выбор версии ядра
KERNEL_VERSION="5.10"

# Архитектура
ARCH="arm"

# Конфигурация процессора
CPU="armv7-a"

# Определение типа ядра
KERNEL_CONFIG="orangepi_defconfig"

# Включение/выключение драйверов
ENABLE_USB=true
ENABLE_WIFI=true
ENABLE_I2C=false
ENABLE_SPI=false

# Функция для конфигурации ядра
configure_kernel() {
    echo "Настройка ядра для Orange PI с конфигурацией $KERNEL_CONFIG"
    make ARCH=$ARCH $KERNEL_CONFIG
    if $ENABLE_USB; then
        echo "Включение поддержки USB"
        make menuconfig  # Включение драйвера USB в меню
    fi
    if $ENABLE_WIFI; then
        echo "Включение поддержки Wi-Fi"
        make menuconfig  # Включение драйвера Wi-Fi
    fi
    # Сборка ядра
    make -j4
}

# Запуск конфигурации ядра
configure_kernel
