#include "kernel.h"
#include "memory.h"
#include "irq.h"
#include "timers.h"
#include "scheduler.h"

// Инициализация ядра
void kernel_init(void) {
    // Инициализация памяти
    memory_init();
    
    // Инициализация прерываний
    irq_init();
    
    // Инициализация таймеров
    timers_init();
    
    // Инициализация планировщика задач
    scheduler_init();
    
    // Выполнение дополнительных настроек или инициализаций
    // ...

    // Запуск первого процесса
    scheduler_run();
}

// Входная точка ядра
void kernel_start(void) {
    // Инициализация всей системы
    kernel_init();
    
    // Выполнение первой задачи (например, запуск процесса 'init')
    // ...
}
