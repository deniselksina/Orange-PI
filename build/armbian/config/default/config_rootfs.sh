#!/bin/bash

# Настройка корневой файловой системы для BoyJack OS

# Путь к rootfs
ROOTFS_DIR="./rootfs"

# Основные пакеты
PACKAGES="build-essential udev libstdc++6"

# Добавление пакетов в систему
add_packages() {
    echo "Установка основных пакетов: $PACKAGES"
    sudo chroot $ROOTFS_DIR apt update
    sudo chroot $ROOTFS_DIR apt install -y $PACKAGES
}

# Установка минимальных библиотек и утилит
configure_libc() {
    echo "Настройка библиотеки C (libc)"
    sudo chroot $ROOTFS_DIR apt install -y libc6
}

# Установка системы инициализации (например, systemd)
setup_init_system() {
    echo "Настройка systemd для инициализации"
    sudo chroot $ROOTFS_DIR apt install -y systemd
}

# Запуск настройки rootfs
add_packages
configure_libc
setup_init_system
