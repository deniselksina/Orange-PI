setenv bootargs console=ttyS0,115200 root=/dev/mmcblk0p2 rootwait
load mmc 0:1 0x42000000 uImage
load mmc 0:1 0x43000000 boot.scr
bootm 0x42000000 0x43000000
