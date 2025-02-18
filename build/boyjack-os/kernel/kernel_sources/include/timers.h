#ifndef TIMERS_H
#define TIMERS_H

// Структуры и функции для управления таймерами
typedef struct {
    uint32_t timeout_ms;  // Время таймера в миллисекундах
    void (*callback)(void);  // Функция обратного вызова при истечении времени
} timer_t;

// Инициализация таймеров
void timer_init(void);
void timer_set(timer_t *timer);
void timer_interrupt_handler(void);  // Обработчик прерывания для таймеров

#endif // TIMERS_H
