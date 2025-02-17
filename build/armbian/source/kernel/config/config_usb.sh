#!/bin/bash

# Установим необходимые параметры для поддержки USB устройств
echo "Настройка поддержки USB устройств..."

# Включаем поддержку USB
echo "Включаем поддержку USB..."
echo "CONFIG_USB_SUPPORT=y" >> .config  # Основная поддержка USB

# Поддержка USB хост-контроллеров
echo "Включаем поддержку USB хост-контроллеров..."
echo "CONFIG_USB_XHCI_HCD=m" >> .config  # Поддержка USB 3.0 хоста
echo "CONFIG_USB_EHCI_HCD=m" >> .config  # Поддержка USB 2.0 хоста

# Подключение драйверов для USB Wi-Fi адаптеров
echo "Включаем драйверы для USB Wi-Fi..."
echo "CONFIG_USB_NET_DRIVERS=y" >> .config  # Поддержка сетевых драйверов для USB-устройств
echo "CONFIG_USB_RTL8187=m" >> .config  # Драйвер для Realtek RTL8187 Wi-Fi адаптера
echo "CONFIG_USB_8188EU=m" >> .config  # Драйвер для других адаптеров на основе Realtek 8188

# Подключение драйверов для USB камер
echo "Включаем драйверы для USB камер..."
echo "CONFIG_VIDEO_DEV=m" >> .config  # Поддержка видеоустройств через USB
echo "CONFIG_USB_VIDEO_CLASS=m" >> .config  # Поддержка USB видеокамер
echo "CONFIG_USB_UVC=m" >> .config  # Поддержка UVC (USB Video Class)

# Включаем поддержку USB-хранилищ
echo "Включаем поддержку USB хранилищ..."
echo "CONFIG_USB_STORAGE=m" >> .config  # Поддержка USB-накопителей
echo "CONFIG_USB_UAS=m" >> .config  # Поддержка USB Attached SCSI (для улучшенной производительности)

# Настройка работы с другими USB устройствами
echo "Настроим поддержку других USB устройств..."
echo "CONFIG_USB_SERIAL=y" >> .config  # Поддержка USB последовательных портов
echo "CONFIG_USB_PRINTER=y" >> .config  # Поддержка USB принтеров

# Установка дополнительных утилит для работы с USB
echo "Устанавливаем утилиты для работы с USB..."
apt-get install -y usbutils

echo "Поддержка USB устройств настроена успешно."
