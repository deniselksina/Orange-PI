// touchpad_driver.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/input.h>

static struct input_dev *touchpad_dev;

static int __init touchpad_driver_init(void) {
    int error;

    // Создание устройства ввода для сенсорной панели
    touchpad_dev = input_allocate_device();
    if (!touchpad_dev) {
        pr_err("Failed to allocate input device\n");
        return -ENOMEM;
    }

    // Установка типов событий для сенсорной панели
    touchpad_dev->evbit[0] = BIT_MASK(EV_ABS) | BIT_MASK(EV_SYN);
    touchpad_dev->abbit[0] = BIT_MASK(ABS_X) | BIT_MASK(ABS_Y); // Координаты касания
    input_set_abs_params(touchpad_dev, ABS_X, 0, 1024, 0, 0); // Диапазон координат X
    input_set_abs_params(touchpad_dev, ABS_Y, 0, 768, 0, 0);  // Диапазон координат Y

    // Регистрируем устройство ввода
    error = input_register_device(touchpad_dev);
    if (error) {
        pr_err("Failed to register input device\n");
        input_free_device(touchpad_dev);
        return error;
    }

    pr_info("Touchpad driver initialized\n");
    return 0;
}

static void __exit touchpad_driver_exit(void) {
    // Отменить регистрацию устройства
    input_unregister_device(touchpad_dev);
    pr_info("Touchpad driver exited\n");
}

module_init(touchpad_driver_init);
module_exit(touchpad_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author Name");
MODULE_DESCRIPTION("Touchpad Driver");
