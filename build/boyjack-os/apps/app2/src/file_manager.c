#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "file_manager.h"

// Функция для создания каталога
int create_directory(const char *path) {
    if (mkdir(path, 0777) == -1) {
        perror("Ошибка создания каталога");
        return -1;
    }
    return 0;
}

// Функция для удаления файла или каталога
int delete_file_or_directory(const char *path) {
    if (remove(path) == -1) {
        perror("Ошибка удаления файла/каталога");
        return -1;
    }
    return 0;
}

// Функция для перемещения файла
int move_file(const char *src, const char *dest) {
    if (rename(src, dest) == -1) {
        perror("Ошибка перемещения файла");
        return -1;
    }
    return 0;
}

// Функция для получения списка файлов в каталоге
int list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("Ошибка открытия каталога");
        return -1;
    }

    while ((entry = readdir(dp))) {
        printf("%s\n", entry->d_name);
    }
    
    closedir(dp);
    return 0;
}
