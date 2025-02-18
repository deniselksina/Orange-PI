#ifndef SCHEDULER_H
#define SCHEDULER_H

// Структуры данных для процессов и очередей
typedef struct task {
    uint32_t task_id;           // Уникальный идентификатор задачи
    uint32_t priority;          // Приоритет задачи
    void (*task_function)(void);  // Указатель на функцию задачи
} task_t;

// Инициализация планировщика
void scheduler_init(void);
void scheduler_add_task(task_t *task);
void scheduler_remove_task(uint32_t task_id);
void scheduler_schedule(void);  // Основной цикл планировщика

#endif // SCHEDULER_H
