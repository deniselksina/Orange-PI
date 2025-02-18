#ifndef NETWORK_H
#define NETWORK_H

// Структура для представления сетевого интерфейса
typedef struct {
    uint32_t ip_address;         // IP-адрес интерфейса
    uint32_t subnet_mask;        // Маска подсети
    uint32_t gateway;            // Шлюз
    uint32_t mac_address[6];     // MAC-адрес интерфейса
    uint32_t mtu;                // Максимальный размер передачи
} network_interface_t;

// Протоколы
#define PROTOCOL_TCP    1
#define PROTOCOL_UDP    2
#define PROTOCOL_ICMP   3

// Функции для работы с сетью
void network_init(void);                              // Инициализация сетевых интерфейсов
void network_send(uint8_t *packet, uint32_t size);    // Отправка пакета
void network_receive(uint8_t *buffer, uint32_t size); // Прием пакета
void network_configure_interface(network_interface_t *iface);  // Настройка интерфейса

#endif // NETWORK_H
