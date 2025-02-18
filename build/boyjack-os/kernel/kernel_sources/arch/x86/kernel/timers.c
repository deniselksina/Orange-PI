#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

// Настройка системного таймера
void init_timer() {
    printf("Инициализация системного таймера для x86...\n");
    // Здесь может быть настройка аппаратного таймера или виртуального таймера
}

// Таймер с задержкой
void delay_ms(uint32_t milliseconds) {
    usleep(milliseconds * 1000);  // Ожидание в миллисекундах
    printf("Задержка на %d миллисекунд завершена.\n", milliseconds);
}

// Получение текущего системного времени (например, в микросекундах)
uint64_t get_system_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}
