#ifndef SIGNAL_H
#define SIGNAL_H

// Структура сигнала
typedef struct {
    uint32_t signal_id;       // Уникальный идентификатор сигнала
    uint32_t sender_pid;      // PID отправителя
    uint32_t receiver_pid;    // PID получателя
    uint32_t data;            // Дополнительные данные сигнала
} signal_t;

// Типы сигналов
#define SIGNAL_INTERRUPT 1
#define SIGNAL_TERMINATE 2
#define SIGNAL_TIMEOUT    3

// Функции для обработки сигналов
void signal_send(signal_t *signal);        // Отправка сигнала
void signal_receive(uint32_t pid, signal_t *signal);  // Получение сигнала для процесса
void signal_handler(signal_t *signal);     // Обработчик сигнала

#endif // SIGNAL_H
