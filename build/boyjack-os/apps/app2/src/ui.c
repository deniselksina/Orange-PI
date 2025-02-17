#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_manager.h"

// Обработчик события для кнопки "Создать каталог"
void on_create_directory_clicked(GtkWidget *widget, gpointer data) {
    const char *path = gtk_entry_get_text(GTK_ENTRY(data));
    if (create_directory(path) == 0) {
        printf("Каталог '%s' успешно создан!\n", path);
    }
}

// Обработчик события для кнопки "Удалить файл/каталог"
void on_delete_file_clicked(GtkWidget *widget, gpointer data) {
    const char *path = gtk_entry_get_text(GTK_ENTRY(data));
    if (delete_file_or_directory(path) == 0) {
        printf("Файл или каталог '%s' успешно удален!\n", path);
    }
}

// Инициализация графического интерфейса
int initialize_ui() {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *create_button;
    GtkWidget *delete_button;
    GtkWidget *path_entry;

    // Инициализация GTK
    gtk_init(NULL, NULL);

    // Создание основного окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Файловый менеджер");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    // Включаем обработку событий для окна
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Создание контейнера для кнопок и поля ввода
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Поле ввода пути
    path_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), path_entry, FALSE, FALSE, 0);

    // Кнопка для создания каталога
    create_button = gtk_button_new_with_label("Создать каталог");
    g_signal_connect(create_button, "clicked", G_CALLBACK(on_create_directory_clicked), path_entry);
    gtk_box_pack_start(GTK_BOX(vbox), create_button, FALSE, FALSE, 0);

    // Кнопка для удаления файла или каталога
    delete_button = gtk_button_new_with_label("Удалить файл/каталог");
    g_signal_connect(delete_button, "clicked", G_CALLBACK(on_delete_file_clicked), path_entry);
    gtk_box_pack_start(GTK_BOX(vbox), delete_button, FALSE, FALSE, 0);

    // Отображаем все элементы
    gtk_widget_show_all(window);

    return 0;
}

// Запуск основного цикла обработки событий
void run_main_loop() {
    gtk_main();
}
