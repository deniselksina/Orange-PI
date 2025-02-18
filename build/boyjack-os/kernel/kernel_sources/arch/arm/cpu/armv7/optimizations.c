#include <stdio.h>

// Оптимизация работы с памятью через выравнивание данных
void memory_optimization_example() {
    int *aligned_data = (int *)__builtin_align_malloc(4 * sizeof(int), 16); // 16-байтное выравнивание

    if (aligned_data) {
        for (int i = 0; i < 4; i++) {
            aligned_data[i] = i;
        }

        for (int i = 0; i < 4; i++) {
            printf("Aligned data[%d] = %d\n", i, aligned_data[i]);
        }

        __builtin_free(aligned_data);  // Освобождение памяти
    } else {
        printf("Memory allocation failed\n");
    }
}

// Оптимизация с использованием инструкций для ускорения арифметических операций
void fast_multiply_example() {
    int a = 10, b = 5, result;

    // Использование ускоренной инструкции для умножения
    __asm__ (
        "mul %0, %1, %2\n"  // Множество a и b, результат в %0
        : "=r" (result)
        : "r" (a), "r" (b)
    );

    printf("Optimized multiplication result: %d\n", result);
}

int main() {
    printf("ARMv7 optimization demo\n");

    memory_optimization_example(); // Пример оптимизации памяти
    fast_multiply_example();       // Пример оптимизации арифметики

    return 0;
}
