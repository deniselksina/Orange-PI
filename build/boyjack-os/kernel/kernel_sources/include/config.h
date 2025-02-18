#ifndef CONFIG_H
#define CONFIG_H

// Структура для конфигурации ядра
typedef struct {
    uint32_t max_processes;        // Максимальное количество процессов
    uint32_t max_threads;          // Максимальное количество потоков
    uint32_t log_level;            // Уровень логирования
    char kernel_version[32];       // Версия ядра
    char root_directory[128];      // Путь к корневой директории
} kernel_config_t;

// Уровни логирования
#define LOG_LEVEL_DEBUG   1
#define LOG_LEVEL_INFO    2
#define LOG_LEVEL_WARN    3
#define LOG_LEVEL_ERROR   4

// Функции для конфигурации ядра
void config_load(void);                           // Загрузка конфигурации из файла
void config_set(kernel_config_t *config);        // Установка конфигурации ядра
void config_save(kernel_config_t *config);       // Сохранение конфигурации в файл

#endif // CONFIG_H
