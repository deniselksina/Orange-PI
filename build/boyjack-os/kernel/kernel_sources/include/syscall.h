#ifndef SYSCALL_H
#define SYSCALL_H

// Определение системных вызовов
#define SYSCALL_EXIT       1  // Завершение процесса
#define SYSCALL_FORK       2  // Создание нового процесса
#define SYSCALL_READ       3  // Чтение данных
#define SYSCALL_WRITE      4  // Запись данных

// Прототипы системных вызовов
void syscall_handler(uint32_t syscall_number, uint32_t *args);

#endif // SYSCALL_H
