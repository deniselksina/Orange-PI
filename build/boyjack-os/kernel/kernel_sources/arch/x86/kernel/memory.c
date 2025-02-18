#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Инициализация памяти
void init_memory() {
    printf("Инициализация памяти для x86...\n");
    // Здесь можно инициализировать память или настроить MMU
}

// Выделение памяти
void* allocate_memory(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }
    printf("Выделено %zu байт памяти.\n", size);
    return ptr;
}

// Освобождение памяти
void free_memory(void* ptr) {
    free(ptr);
    printf("Память освобождена.\n");
}
