#!/bin/bash

# Оптимизация работы системы
ENABLE_SWAPPINESS="false"
MAX_FILE_HANDLES="10240"
FS_INODE_CACHE="true"

# Настройки CPU
CPU_GOVERNOR="performance"
CPU_FREQ="2.5GHz"

# Монтирование жестких дисков
MOUNT_FSTAB="/etc/fstab"
