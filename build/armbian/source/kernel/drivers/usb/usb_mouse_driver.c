// usb_mouse_driver.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

static struct usb_device_id usb_mouse_table[] = {
    { USB_DEVICE(0x046d, 0xc018) },  // Пример идентификатора устройства (Logitech)
    {} /* конец списка */
};

static int usb_mouse_probe(struct usb_interface *interface, const struct usb_device_id *id) {
    printk(KERN_INFO "USB Mouse detected\n");
    return 0;
}

static void usb_mouse_disconnect(struct usb_interface *interface) {
    printk(KERN_INFO "USB Mouse disconnected\n");
}

static struct usb_driver usb_mouse_driver = {
    .name = "usb_mouse_driver",
    .id_table = usb_mouse_table,
    .probe = usb_mouse_probe,
    .disconnect = usb_mouse_disconnect,
};

static int __init usb_mouse_init(void) {
    int result = usb_register(&usb_mouse_driver);
    if (result < 0) {
        printk(KERN_ERR "usb_register failed for usb_mouse_driver\n");
        return result;
    }
    printk(KERN_INFO "USB Mouse driver registered\n");
    return 0;
}

static void __exit usb_mouse_exit(void) {
    usb_deregister(&usb_mouse_driver);
    printk(KERN_INFO "USB Mouse driver deregistered\n");
}

module_init(usb_mouse_init);
module_exit(usb_mouse_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("USB Mouse Driver");
