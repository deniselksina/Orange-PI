# Основные настройки для U-Boot на Orange PI
setenv bootcmd 'mmc dev 0; fatload mmc 0:1 ${loadaddr} uImage; bootm ${loadaddr}'
setenv bootargs 'console=tty1 root=/dev/mmcblk0p2 rootfstype=ext4'
setenv loadaddr 0x46000000
setenv fdtfile sun7i-a20-orangepi.dtb
