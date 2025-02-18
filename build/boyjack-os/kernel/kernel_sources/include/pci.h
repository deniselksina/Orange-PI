#ifndef PCI_H
#define PCI_H

#include <stdint.h>

#define PCI_MAX_DEVICES       32
#define PCI_VENDOR_ID         0x8086  // Пример: ID производителя Intel

// Структура для представления PCI устройства
typedef struct {
    uint16_t vendor_id;     // Идентификатор производителя
    uint16_t device_id;     // Идентификатор устройства
    uint8_t class_code;     // Класс устройства
    uint8_t subclass_code;  // Подкласс устройства
    uint8_t bus;            // Шина устройства
    uint8_t device;         // Устройство на шине
    uint8_t function;       // Функция устройства
} pci_device_t;

// Инициализация PCI подсистемы
void pci_init(void);

// Поиск PCI устройств
pci_device_t *pci_find_device(uint16_t vendor_id, uint16_t device_id);

#endif // PCI_H
