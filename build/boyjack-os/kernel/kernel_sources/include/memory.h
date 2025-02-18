#ifndef MEMORY_H
#define MEMORY_H

// Структуры для управления памятью
typedef struct {
    void *start;        // Начало блока памяти
    size_t size;        // Размер блока памяти
} memory_block_t;

// Функции управления памятью
void *mem_alloc(size_t size);   // Выделение памяти
void mem_free(void *ptr);       // Освобождение памяти
void memory_init(void);         // Инициализация памяти

#endif // MEMORY_H
