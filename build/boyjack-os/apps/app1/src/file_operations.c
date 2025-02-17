#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH 256  // Максимальная длина пути к файлу

// Структура для хранения информации о файле
static FILE *current_file = NULL;  // Указатель на открытый файл
static char current_file_path[MAX_FILE_PATH] = {0};  // Путь к текущему файлу

// Функция для открытия файла
int open_file(const char *file_path) {
    current_file = fopen(file_path, "r+");  // Открываем файл для чтения и записи
    if (!current_file) {
        // Если файл не существует, создаем новый
        current_file = fopen(file_path, "w+");
        if (!current_file) {
            printf("Ошибка: не удалось открыть файл %s.\n", file_path);
            return -1;  // Возвращаем ошибку
        }
    }
    
    // Сохраняем путь к открытому файлу
    strncpy(current_file_path, file_path, MAX_FILE_PATH - 1);
    printf("Файл %s открыт.\n", file_path);
    return 0;  // Успешно
}

// Функция для закрытия файла
void close_file() {
    if (current_file) {
        fclose(current_file);  // Закрываем файл
        current_file = NULL;
        memset(current_file_path, 0, sizeof(current_file_path));  // Очистка пути
        printf("Файл закрыт.\n");
    } else {
        printf("Ошибка: файл не был открыт.\n");
    }
}

// Функция для сохранения текста в файл
int save_file(const char *text) {
    if (!current_file) {
        printf("Ошибка: файл не открыт для сохранения.\n");
        return -1;
    }

    fseek(current_file, 0, SEEK_SET);  // Перемещаем указатель в начало файла
    if (fwrite(text, sizeof(char), strlen(text), current_file) != strlen(text)) {
        printf("Ошибка: не удалось записать данные в файл.\n");
        return -1;  // Ошибка записи
    }

    fflush(current_file);  // Сохраняем данные на диск
    printf("Файл сохранён в %s.\n", current_file_path);
    return 0;  // Успешно
}

// Функция для загрузки содержимого файла в текст
int load_file(char *buffer, size_t buffer_size) {
    if (!current_file) {
        printf("Ошибка: файл не открыт для загрузки.\n");
        return -1;
    }

    fseek(current_file, 0, SEEK_SET);  // Перемещаем указатель в начало файла
    size_t bytes_read = fread(buffer, sizeof(char), buffer_size - 1, current_file);
    if (bytes_read == 0) {
        printf("Ошибка: не удалось прочитать файл или файл пуст.\n");
        return -1;
    }

    buffer[bytes_read] = '\0';  // Завершаем строку
    printf("Файл %s загружен.\n", current_file_path);
    return 0;  // Успешно
}
