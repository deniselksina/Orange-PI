#ifndef KERNEL_H
#define KERNEL_H

// Основные определения и глобальные переменные
#define KERNEL_VERSION "1.0.0"

// Структуры данных для инициализации
extern void kernel_init(void);  // Функция инициализации ядра
extern void kernel_shutdown(void);  // Завершение работы ядра

#endif // KERNEL_H
