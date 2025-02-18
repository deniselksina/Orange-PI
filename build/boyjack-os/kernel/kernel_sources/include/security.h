#ifndef SECURITY_H
#define SECURITY_H

// Структура для представления пользователя
typedef struct {
    uint32_t user_id;         // Уникальный идентификатор пользователя
    char username[32];        // Имя пользователя
    char password[64];        // Пароль (зашифрован)
    uint32_t permissions;     // Права доступа (например, чтение, запись)
} user_t;

// Права доступа
#define PERMISSION_READ    1
#define PERMISSION_WRITE   2
#define PERMISSION_EXECUTE 4

// Функции безопасности
void security_init(void);                             // Инициализация системы безопасности
int security_check_permission(uint32_t user_id, uint32_t permission); // Проверка прав доступа
void security_authenticate(user_t *user);             // Аутентификация пользователя
void security_encrypt_data(uint8_t *data, uint32_t size); // Шифрование данных

#endif // SECURITY_H
