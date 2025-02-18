#include <arm_neon.h>
#include <stdio.h>

// Пример использования NEON (SIMD) для векторных операций
void neon_example() {
    // Пример: сложение двух векторов с помощью NEON
    int32x4_t a = vld1q_s32((int32_t[]){1, 2, 3, 4});
    int32x4_t b = vld1q_s32((int32_t[]){5, 6, 7, 8});
    int32x4_t result = vaddq_s32(a, b);

    int32_t res[4];
    vst1q_s32(res, result);
    
    printf("NEON result: %d, %d, %d, %d\n", res[0], res[1], res[2], res[3]);
}

// Пример работы с инструкциями ARMv7 для управления состоянием процессора
void cpsid_example() {
    __asm__ volatile (
        "cpsid i\n"   // Отключение прерываний
        "nop\n"
        "cpsie i\n"   // Включение прерываний
    );
    printf("Interrupts disabled and re-enabled\n");
}

int main() {
    printf("ARMv7 specific instructions demo\n");

    neon_example();  // Пример NEON
    cpsid_example(); // Пример управления прерываниями

    return 0;
}
