// keyboard_driver.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/input.h>

static struct input_dev *keyboard_dev;

static int __init keyboard_driver_init(void) {
    int error;

    // Создание устройства ввода для клавиатуры
    keyboard_dev = input_allocate_device();
    if (!keyboard_dev) {
        pr_err("Failed to allocate input device\n");
        return -ENOMEM;
    }

    // Установка типов событий для клавиатуры
    keyboard_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_SYN);
    keyboard_dev->keybit[BIT_WORD(KEY_A)] = BIT_MASK(KEY_A); // Пример для клавиши "A"

    // Регистрируем устройство ввода
    error = input_register_device(keyboard_dev);
    if (error) {
        pr_err("Failed to register input device\n");
        input_free_device(keyboard_dev);
        return error;
    }

    pr_info("Keyboard driver initialized\n");
    return 0;
}

static void __exit keyboard_driver_exit(void) {
    // Отменить регистрацию устройства
    input_unregister_device(keyboard_dev);
    pr_info("Keyboard driver exited\n");
}

module_init(keyboard_driver_init);
module_exit(keyboard_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("Keyboard Driver");
