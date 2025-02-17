#!/bin/bash

# Установим необходимые параметры ядра для сетевых устройств
echo "Настройка сетевых параметров..."

# Включение поддержки Ethernet
echo "Включаем поддержку Ethernet..."
echo "CONFIG_NET_VENDOR_REALTEK=y" >> .config
echo "CONFIG_RTL8187=m" >> .config  # Драйвер для Realtek RTL8187 USB Wi-Fi

# Включение поддержки Wi-Fi
echo "Включаем поддержку Wi-Fi..."
echo "CONFIG_WIRELESS=m" >> .config  # Основная поддержка Wi-Fi
echo "CONFIG_LIBERTAS_USB=m" >> .config  # Драйвер для Wi-Fi адаптеров на основе Libertas

# Включаем поддержку WPA
echo "Включаем поддержку WPA..."
echo "CONFIG_WPA_SUPPLICANT=m" >> .config  # WPA Supplicant для безопасных соединений

# Установка параметров IP и сетевых интерфейсов
echo "Настройка параметров IP..."
echo "CONFIG_INET=m" >> .config  # Поддержка IP (IPv4 и IPv6)
echo "CONFIG_NETFILTER=y" >> .config  # Включение поддержки сетевого фильтра

# Настройка дополнительных опций сети
echo "Настроим дополнительные опции сети..."
echo "CONFIG_IPV6=y" >> .config  # Включение поддержки IPv6
echo "CONFIG_IP_MULTICAST=y" >> .config  # Мультикаст

# Сетевые утилиты
echo "Устанавливаем утилиты для настройки сети..."
apt-get install -y net-tools iproute2 wireless-tools

echo "Сетевые параметры настроены успешно."
