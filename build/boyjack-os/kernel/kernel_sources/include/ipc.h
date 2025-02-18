#ifndef IPC_H
#define IPC_H

// Структура для обмена сообщениями между процессами
typedef struct {
    uint32_t sender_pid;  // PID отправителя
    uint32_t receiver_pid; // PID получателя
    uint32_t message_id;  // Уникальный идентификатор сообщения
    uint32_t *data;       // Указатель на данные сообщения
} message_t;

// Функции для межпроцессного взаимодействия
void ipc_send(message_t *message);  // Отправка сообщения
message_t* ipc_receive(uint32_t pid);  // Получение сообщения для процесса
void ipc_init(void);               // Инициализация IPC системы

#endif // IPC_H
