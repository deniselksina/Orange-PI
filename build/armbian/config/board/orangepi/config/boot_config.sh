#!/bin/bash

# Конфигурация загрузки для Orange PI
BOOT_PARTITION="/dev/mmcblk0p1"
ROOT_PARTITION="/dev/mmcblk0p2"
BOOT_DIR="/boot"

# Копирование ядра на boot раздел
cp $ROOTFS/boot/uImage $BOOT_DIR
cp $ROOTFS/boot/dtbs/*.dtb $BOOT_DIR
cp $ROOTFS/boot/boot.cmd $BOOT_DIR
sync

# Настройка загрузчика U-Boot
echo "bootcmd=mmc dev 0; mmc rescan; run bootcmd_mmc" > $BOOT_DIR/boot.scr
