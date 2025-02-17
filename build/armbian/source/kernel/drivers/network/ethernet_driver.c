// ethernet_driver.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netdevice.h>

static int ethernet_init(struct net_device *dev) {
    printk(KERN_INFO "Ethernet driver initialized\n");
    return 0;
}

static struct net_device_ops ethernet_netdev_ops = {
    .ndo_init = ethernet_init,
};

static struct net_device *eth_device;

static int __init ethernet_driver_init(void) {
    eth_device = alloc_netdev(0, "eth0", NET_NAME_UNKNOWN, ethernet_init);
    eth_device->netdev_ops = &ethernet_netdev_ops;
    register_netdev(eth_device);
    printk(KERN_INFO "Ethernet driver loaded\n");
    return 0;
}

static void __exit ethernet_driver_exit(void) {
    unregister_netdev(eth_device);
    printk(KERN_INFO "Ethernet driver unloaded\n");
}

module_init(ethernet_driver_init);
module_exit(ethernet_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("Ethernet driver");
