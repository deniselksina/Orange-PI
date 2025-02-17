#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

int main() {
    // Инициализация графического интерфейса
    if (initialize_ui() != 0) {
        fprintf(stderr, "Ошибка инициализации интерфейса.\n");
        return 1;
    }

    // Запуск главного цикла обработки событий
    run_main_loop();

    return 0;
}
