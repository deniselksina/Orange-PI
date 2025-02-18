#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Ethernet Driver");

static struct net_device *net_dev;

static int eth_open(struct net_device *dev)
{
    pr_info("Ethernet device opened\n");
    netif_start_queue(dev);
    return 0;
}

static int eth_close(struct net_device *dev)
{
    pr_info("Ethernet device closed\n");
    netif_stop_queue(dev);
    return 0;
}

static int eth_xmit(struct sk_buff *skb, struct net_device *dev)
{
    pr_info("Transmitting Ethernet frame\n");

    // Отправка данных через Ethernet интерфейс
    dev_kfree_skb(skb);
    return 0;
}

static struct net_device_ops eth_netdev_ops = {
    .ndo_open = eth_open,
    .ndo_stop = eth_close,
    .ndo_start_xmit = eth_xmit,
};

static void eth_setup(struct net_device *dev)
{
    ether_setup(dev);
    dev->netdev_ops = &eth_netdev_ops;
}

static int __init ethernet_init(void)
{
    pr_info("Initializing Ethernet driver...\n");

    // Создание сетевого устройства
    net_dev = alloc_netdev(0, "eth0", NET_NAME_UNKNOWN, eth_setup);
    if (!net_dev) {
        pr_err("Failed to allocate network device\n");
        return -ENOMEM;
    }

    // Регистрация сетевого устройства
    if (register_netdev(net_dev)) {
        pr_err("Failed to register network device\n");
        free_netdev(net_dev);
        return -ENODEV;
    }

    pr_info("Ethernet driver initialized successfully\n");
    return 0;
}

static void __exit ethernet_exit(void)
{
    pr_info("Shutting down Ethernet driver...\n");

    // Остановка и удаление сетевого устройства
    unregister_netdev(net_dev);
    free_netdev(net_dev);

    pr_info("Ethernet driver shutdown successfully\n");
}

module_init(ethernet_init);
module_exit(ethernet_exit);
