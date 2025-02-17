#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>  // Используем ncurses для создания текстового пользовательского интерфейса

#define MAX_TEXT_SIZE 1024  // Максимальный размер текста в редакторе

static char text_buffer[MAX_TEXT_SIZE];  // Буфер для текста в редакторе
static int cursor_pos = 0;  // Позиция курсора в тексте

// Функция для инициализации пользовательского интерфейса
void init_ui() {
    initscr();  // Инициализация ncurses
    raw();      // Отключаем буферизацию ввода
    keypad(stdscr, TRUE);  // Включаем поддержку функциональных клавиш
    noecho();   // Отключаем отображение ввода
    curs_set(1);  // Показываем курсор

    // Устанавливаем размер окна
    resize_term(24, 80);  // Устанавливаем размер окна (например, 24 строки и 80 столбцов)
    clear();  // Очищаем экран
    refresh();  // Обновляем экран

    // Инициализация буфера текста
    memset(text_buffer, 0, sizeof(text_buffer));
    cursor_pos = 0;
}

// Функция для отображения текста в редакторе
void display_text() {
    clear();  // Очищаем экран

    // Отображаем текст в окне
    mvprintw(0, 0, "Text Editor - Press F1 to Save, F2 to Open, F3 to Quit");

    // Отображаем содержимое текста в буфере
    mvprintw(2, 0, "Text Content:");
    mvprintw(3, 0, "%s", text_buffer);

    // Устанавливаем курсор в соответствующую позицию
    move(3, cursor_pos);  // Перемещаем курсор в нужное место
    refresh();  // Обновляем экран
}

// Функция для обработки ввода символов в редактор
void handle_input() {
    int ch;
    while ((ch = getch()) != KEY_F(3)) {  // Пока не нажата клавиша F3 (выход)
        if (ch == KEY_F(1)) {
            // Сохранить файл (будет реализовано в другом месте)
            // save_file(text_buffer);
        } else if (ch == KEY_F(2)) {
            // Открыть файл (будет реализовано в другом месте)
            // open_file("example.txt");
        } else if (ch == KEY_BACKSPACE || ch == 127) {
            // Удалить символ
            if (cursor_pos > 0) {
                cursor_pos--;
                text_buffer[cursor_pos] = '\0';  // Удаляем последний символ
            }
        } else if (ch == '\n') {
            // Перенос строки (обработка по необходимости)
            // Пока просто добавляем символ новой строки
            text_buffer[cursor_pos] = '\n';
            cursor_pos++;
        } else {
            // Добавить символ в текст
            if (cursor_pos < MAX_TEXT_SIZE - 1) {
                text_buffer[cursor_pos] = (char)ch;
                cursor_pos++;
            }
        }

        display_text();  // Отображаем обновленный текст
    }
}

// Функция для завершения работы с интерфейсом
void cleanup_ui() {
    endwin();  // Завершаем работу с ncurses
}
