#!/bin/bash

# Сборка U-Boot для Orange PI
cd /path/to/uboot
make distclean
make orangepi_pc_defconfig
make
