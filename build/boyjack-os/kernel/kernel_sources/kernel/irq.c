#include "irq.h"
#include "kernel.h"

// Массив обработчиков прерываний
static irq_handler_t irq_handlers[IRQ_MAX];

// Инициализация системы прерываний
void irq_init(void) {
    for (int i = 0; i < IRQ_MAX; i++) {
        irq_handlers[i] = NULL;
    }
    // Дополнительная инициализация аппаратных прерываний
    // ...
}

// Регистрация обработчика прерывания
void irq_register_handler(int irq, irq_handler_t handler) {
    if (irq < 0 || irq >= IRQ_MAX) {
        return;
    }
    irq_handlers[irq] = handler;
}

// Обработка прерываний
void irq_handle(int irq) {
    if (irq < 0 || irq >= IRQ_MAX || irq_handlers[irq] == NULL) {
        return;
    }
    irq_handlers[irq]();  // Вызов обработчика прерывания
}

// Основной цикл обработки прерываний
void irq_dispatch(void) {
    int irq = get_current_irq();  // Функция получения текущего номера прерывания
    irq_handle(irq);
}
