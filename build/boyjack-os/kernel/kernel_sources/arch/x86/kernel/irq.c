#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Структура для хранения информации о прерывании
struct irq_handler {
    void (*handler)(void);  // Функция обработки прерывания
    uint32_t irq_number;    // Номер прерывания
};

// Массив для хранения обработчиков прерываний
#define MAX_IRQ_HANDLERS 256
static struct irq_handler irq_handlers[MAX_IRQ_HANDLERS];

// Инициализация прерываний
void irq_init() {
    printf("Инициализация системы прерываний...\n");

    // Регистрация обработчиков прерываний
    for (int i = 0; i < MAX_IRQ_HANDLERS; i++) {
        irq_handlers[i].handler = NULL;
    }
}

// Регистрация обработчика прерывания
void register_irq_handler(uint32_t irq_number, void (*handler)(void)) {
    if (irq_number < MAX_IRQ_HANDLERS) {
        irq_handlers[irq_number].handler = handler;
        printf("Обработчик для IRQ %d зарегистрирован.\n", irq_number);
    }
}

// Обработка прерываний
void handle_irq(uint32_t irq_number) {
    if (irq_number < MAX_IRQ_HANDLERS && irq_handlers[irq_number].handler != NULL) {
        irq_handlers[irq_number].handler();
        printf("Обработано прерывание для IRQ %d.\n", irq_number);
    } else {
        printf("Неизвестное прерывание: IRQ %d.\n", irq_number);
    }
}
