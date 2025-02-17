#include "editor.h"
#include <string.h>
#include <stdio.h>

#define MAX_TEXT_LENGTH 1024  // Максимальный размер текста

// Структура для хранения текста
static char text[MAX_TEXT_LENGTH];

// Функция для инициализации редактора
void init_editor() {
    memset(text, 0, sizeof(text));  // Инициализируем текст как пустой
}

// Функция для вставки текста
void insert_text(const char *new_text) {
    if (strlen(text) + strlen(new_text) < MAX_TEXT_LENGTH) {
        strcat(text, new_text);  // Добавляем новый текст в конец
    } else {
        printf("Ошибка: недостаточно места для вставки текста.\n");
    }
}

// Функция для удаления текста с конца
void delete_text(int length) {
    int current_length = strlen(text);
    if (length > current_length) {
        printf("Ошибка: пытаетесь удалить больше текста, чем есть.\n");
        return;
    }
    text[current_length - length] = '\0';  // Удаляем последние символы
}

// Функция для замены текста в заданной позиции
void replace_text(int start_pos, const char *new_text) {
    int len = strlen(new_text);
    if (start_pos >= 0 && start_pos + len <= MAX_TEXT_LENGTH) {
        strncpy(text + start_pos, new_text, len);  // Заменяем текст
    } else {
        printf("Ошибка: неверная позиция или длина текста для замены.\n");
    }
}

// Функция для отображения текущего текста в редакторе
void display_text() {
    printf("Текущий текст:\n%s\n", text);
}

