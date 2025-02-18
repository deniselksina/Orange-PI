#ifndef IRQ_H
#define IRQ_H

// Структура для обработки прерываний
typedef struct {
    void (*handler)(void);  // Указатель на обработчик прерывания
    int irq_number;         // Номер прерывания
} irq_entry_t;

// Инициализация обработчиков прерываний
void irq_init(void);
void irq_enable(int irq_number);
void irq_disable(int irq_number);
void irq_handler(int irq_number);

#endif // IRQ_H
