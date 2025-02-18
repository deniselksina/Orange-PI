#ifndef DEBUG_H
#define DEBUG_H

// Макросы для отладки
#define DEBUG_LOG(msg)    printf("DEBUG: %s\n", msg)   // Логирование сообщений
#define DEBUG_TRACE()      printf("TRACE: %s:%d\n", __FILE__, __LINE__)  // Трассировка вызова

// Функции для отладки
void debug_init(void);                        // Инициализация системы отладки
void debug_log(const char *msg);              // Логирование сообщения
void debug_print_trace(void);                 // Печать трассировки

#endif // DEBUG_H
