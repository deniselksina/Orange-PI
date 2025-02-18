#include "timers.h"
#include "cpu.h"
#include "irq.h"

void init_timers(void) {
    // Инициализация таймеров ARM
    configure_timer_interrupt();
    start_system_timer();
}

void configure_timer_interrupt(void) {
    // Настройка прерывания по таймеру
}

void start_system_timer(void) {
    // Запуск системного таймера
}

void handle_timer_interrupt(void) {
    // Обработка прерывания от системного таймера
    increment_system_time();
    schedule();
}
