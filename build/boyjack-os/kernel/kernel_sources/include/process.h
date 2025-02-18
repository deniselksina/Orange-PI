#ifndef PROCESS_H
#define PROCESS_H

// Структура для представления процесса
typedef struct {
    uint32_t pid;           // Уникальный идентификатор процесса
    uint32_t state;         // Состояние процесса (например, RUNNING, WAITING)
    uint32_t priority;      // Приоритет процесса
    uint32_t *stack_ptr;    // Указатель на стек процесса
    void (*entry_point)(void);  // Точка входа для процесса
} process_t;

// Состояния процессов
#define PROCESS_RUNNING 0
#define PROCESS_WAITING 1
#define PROCESS_TERMINATED 2

// Функции для управления процессами
void process_init(void);              // Инициализация процесса
void process_create(process_t *process);  // Создание нового процесса
void process_terminate(uint32_t pid);  // Завершение процесса
void process_switch(process_t *next_process);  // Переключение между процессами

#endif // PROCESS_H
