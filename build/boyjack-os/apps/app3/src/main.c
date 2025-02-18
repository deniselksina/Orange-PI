#include <stdio.h>
#include <stdlib.h>
#include "browser.h"
#include "network.h"
#include "ui.h"

int main(int argc, char *argv[]) {
    printf("Запуск приложения...\n");

    // Инициализация сетевых модулей
    if (network_init() != 0) {
        fprintf(stderr, "Ошибка инициализации сети\n");
        return EXIT_FAILURE;
    }

    // Инициализация интерфейса
    if (ui_init() != 0) {
        fprintf(stderr, "Ошибка инициализации интерфейса\n");
        return EXIT_FAILURE;
    }

    // Инициализация браузера/почтового клиента
    if (browser_init() != 0) {
        fprintf(stderr, "Ошибка инициализации браузера/почтового клиента\n");
        return EXIT_FAILURE;
    }

    printf("Приложение успешно запущено!\n");

    // Запуск главного цикла приложения
    main_loop();

    // Очистка и завершение
    browser_cleanup();
    network_cleanup();
    ui_cleanup();

    printf("Приложение завершило работу.\n");
    return EXIT_SUCCESS;
}
