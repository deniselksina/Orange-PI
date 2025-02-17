#!/bin/bash

# Запись U-Boot на SD карту
sudo dd if=u-boot.bin of=/dev/sdX bs=1M seek=8
sync
