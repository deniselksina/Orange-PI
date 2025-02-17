#!/bin/bash

# Обновление U-Boot на Orange PI
cd /path/to/uboot
make
sudo dd if=u-boot.bin of=/dev/sdX bs=1M seek=8
sync
