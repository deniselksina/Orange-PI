#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

// Структуры для работы с файлами
typedef struct {
    uint32_t file_id;      // Уникальный идентификатор файла
    uint32_t size;         // Размер файла
    uint32_t *data;        // Указатель на данные файла
    uint32_t flags;        // Флаги доступа (чтение, запись и т.д.)
} file_t;

// Функции для работы с файловой системой
void fs_init(void);                    // Инициализация файловой системы
file_t* fs_open(const char *path, uint32_t flags);  // Открытие файла
int fs_read(file_t *file, uint32_t *buffer, uint32_t size);  // Чтение данных из файла
int fs_write(file_t *file, uint32_t *data, uint32_t size);  // Запись данных в файл
int fs_close(file_t *file);            // Закрытие файла

#endif // FILE_SYSTEM_H
