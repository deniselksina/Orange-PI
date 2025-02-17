#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Функция для форматирования пути
void format_path(char *path) {
    char formatted_path[1024];
    snprintf(formatted_path, sizeof(formatted_path), "%s/", path);
    strcpy(path, formatted_path);
}

// Функция для обработки ошибок
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
