#ifndef SYNC_H
#define SYNC_H

// Структура мьютекса
typedef struct {
    uint32_t locked;         // Состояние мьютекса (заблокирован/не заблокирован)
    uint32_t owner_pid;      // PID владельца мьютекса
} mutex_t;

// Структура семафора
typedef struct {
    uint32_t value;          // Значение семафора
    uint32_t waiting_pid;    // PID процесса, ожидающего на семафоре
} semaphore_t;

// Функции для синхронизации
void mutex_init(mutex_t *mutex);           // Инициализация мьютекса
void mutex_lock(mutex_t *mutex);           // Захват мьютекса
void mutex_unlock(mutex_t *mutex);         // Освобождение мьютекса
void semaphore_init(semaphore_t *semaphore, uint32_t value);  // Инициализация семафора
void semaphore_wait(semaphore_t *semaphore);  // Ожидание семафора
void semaphore_signal(semaphore_t *semaphore);  // Сигнал семафору

#endif // SYNC_H
