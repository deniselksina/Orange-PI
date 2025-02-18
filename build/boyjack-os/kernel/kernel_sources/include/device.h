#ifndef DEVICE_H
#define DEVICE_H

// Структура для представления устройства
typedef struct {
    uint32_t device_id;      // Уникальный идентификатор устройства
    uint32_t type;           // Тип устройства (например, блок, сеть, USB)
    void (*init)(void);      // Функция инициализации устройства
    void (*read)(uint32_t *buffer, uint32_t size);  // Чтение данных
    void (*write)(const uint32_t *data, uint32_t size); // Запись данных
} device_t;

// Типы устройств
#define DEVICE_TYPE_BLOCK  1
#define DEVICE_TYPE_NETWORK 2
#define DEVICE_TYPE_USB     3

// Функции для работы с устройствами
void device_init(void);                       // Инициализация устройств
void device_register(device_t *device);       // Регистрация нового устройства
void device_unregister(uint32_t device_id);   // Удаление устройства
void device_read(device_t *device, uint32_t *buffer, uint32_t size);  // Чтение с устройства
void device_write(device_t *device, const uint32_t *data, uint32_t size);  // Запись на устройство

#endif // DEVICE_H
