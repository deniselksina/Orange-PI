#!/bin/bash

# Настройки для загрузочных оверлеев и устройств
ENABLE_GPIO=true
ENABLE_SPI=true
ENABLE_I2C=false

# Описание настроек оверлеев
OVRLAY_GPIO="gpio-override.dtb"
OVRLAY_SPI="spi-override.dtb"

# Функция для добавления оверлеев
add_overlay() {
    if [ "$1" == "gpio" ] && $ENABLE_GPIO; then
        echo "Добавление оверлея для GPIO"
        # Здесь можно добавить код для загрузки оверлея
    fi
    if [ "$1" == "spi" ] && $ENABLE_SPI; then
        echo "Добавление оверлея для SPI"
        # Здесь можно добавить код для загрузки оверлея
    fi
}

# Применение оверлеев
add_overlay gpio
add_overlay spi
