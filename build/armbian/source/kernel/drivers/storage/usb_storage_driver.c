// usb_storage_driver.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/storage.h>

static struct usb_device_id usb_storage_table[] = {
    { USB_DEVICE(0x0781, 0x5581) },  // Пример идентификатора USB-накопителя (SanDisk)
    {} /* конец списка */
};

static int usb_storage_probe(struct usb_interface *interface, const struct usb_device_id *id) {
    printk(KERN_INFO "USB storage device detected\n");
    // Инициализация устройства
    return 0;
}

static void usb_storage_disconnect(struct usb_interface *interface) {
    printk(KERN_INFO "USB storage device disconnected\n");
    // Очистка ресурсов
}

static struct usb_driver usb_storage_driver = {
    .name = "usb_storage_driver",
    .id_table = usb_storage_table,
    .probe = usb_storage_probe,
    .disconnect = usb_storage_disconnect,
};

static int __init usb_storage_init(void) {
    int result = usb_register(&usb_storage_driver);
    if (result < 0) {
        printk(KERN_ERR "usb_register failed for usb_storage_driver\n");
        return result;
    }
    printk(KERN_INFO "USB Storage driver registered\n");
    return 0;
}

static void __exit usb_storage_exit(void) {
    usb_deregister(&usb_storage_driver);
    printk(KERN_INFO "USB Storage driver deregistered\n");
}

module_init(usb_storage_init);
module_exit(usb_storage_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("USB Storage Driver");
