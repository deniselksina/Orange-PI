#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABS 10

// Структура для представления вкладки
typedef struct {
    int id;
    char url[256];
    int isActive;
} Tab;

// Массив вкладок
Tab tabs[MAX_TABS];
int currentTab = 0;

// Логика загрузки и рендеринга страницы
void loadPage(const char *url) {
    printf("Загрузка страницы: %s\n", url);
    // Симуляция рендеринга страницы
    printf("Рендеринг содержимого страницы...\n");
}

// Логика управления вкладками
void manageTabs() {
    int choice;
    printf("\nУправление вкладками:\n");
    printf("1. Открыть новую вкладку\n");
    printf("2. Переключиться на вкладку\n");
    printf("3. Закрыть вкладку\n");
    printf("Выберите действие: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (currentTab < MAX_TABS) {
                printf("Введите URL новой вкладки: ");
                scanf("%s", tabs[currentTab].url);
                tabs[currentTab].id = currentTab + 1;
                tabs[currentTab].isActive = 1;
                printf("Новая вкладка с URL: %s открыта.\n", tabs[currentTab].url);
                currentTab++;
            } else {
                printf("Максимальное количество вкладок достигнуто.\n");
            }
            break;
        case 2:
            printf("Введите номер вкладки для переключения: ");
            int tabNumber;
            scanf("%d", &tabNumber);
            if (tabNumber > 0 && tabNumber <= currentTab) {
                printf("Переключение на вкладку %d с URL: %s\n", tabNumber, tabs[tabNumber - 1].url);
            } else {
                printf("Вкладка с таким номером не существует.\n");
            }
            break;
        case 3:
            printf("Введите номер вкладки для закрытия: ");
            scanf("%d", &tabNumber);
            if (tabNumber > 0 && tabNumber <= currentTab) {
                for (int i = tabNumber - 1; i < currentTab - 1; i++) {
                    tabs[i] = tabs[i + 1]; // Сдвиг всех вкладок на одну позицию влево
                }
                currentTab--;
                printf("Вкладка %d закрыта.\n", tabNumber);
            } else {
                printf("Вкладка с таким номером не существует.\n");
            }
            break;
        default:
            printf("Некорректный выбор.\n");
    }
}

// Логика обработки событий навигации
void handleNavigationEvents() {
    printf("\nОбработка событий навигации:\n");
    printf("1. Перезагрузить текущую страницу\n");
    printf("2. Перейти по новому URL\n");
    printf("Выберите действие: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Перезагрузка страницы %s...\n", tabs[currentTab - 1].url);
            break;
        case 2:
            {
                char newUrl[256];
                printf("Введите новый URL: ");
                scanf("%s", newUrl);
                printf("Переход на новый URL: %s\n", newUrl);
                strcpy(tabs[currentTab - 1].url, newUrl); // Обновление URL текущей вкладки
            }
            break;
        default:
            printf("Некорректный выбор.\n");
    }
}

int main() {
    // Открываем начальную страницу
    loadPage("http://example.com");

    // Менеджер вкладок
    manageTabs();

    // Обработка событий навигации
    handleNavigationEvents();

    return 0;
}
