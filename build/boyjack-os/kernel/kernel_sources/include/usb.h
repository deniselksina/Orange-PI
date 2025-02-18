#ifndef USB_H
#define USB_H

#include <stdint.h>

#define USB_MAX_DEVICES    128
#define USB_MAX_ENDPOINTS   16

// Структуры и константы для работы с USB устройствами
typedef struct {
    uint8_t device_address;          // Адрес устройства в системе
    uint16_t vendor_id;              // Идентификатор производителя
    uint16_t product_id;             // Идентификатор продукта
    uint8_t endpoint_count;          // Количество конечных точек устройства
    usb_endpoint_t endpoints[USB_MAX_ENDPOINTS];  // Конечные точки
} usb_device_t;

// Инициализация USB подсистемы
void usb_init(void);

// Поиск подключенных USB устройств
usb_device_t *usb_find_device(uint16_t vendor_id, uint16_t product_id);

// Отправка данных через USB
int usb_send_data(usb_device_t *device, uint8_t *data, uint32_t size);

#endif // USB_H
