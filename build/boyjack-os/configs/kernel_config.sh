#!/bin/bash

# Определение параметров ядра
KERNEL_VERSION="5.10.0"
ENABLE_MODULES=("ext4" "nfs" "vfat")

# Настройки виртуальной памяти
VM_SWAPPINESS="60"
VM_OVERCOMMIT_MEMORY="2"

# Сетевые параметры
NET_IPV6="disabled"
