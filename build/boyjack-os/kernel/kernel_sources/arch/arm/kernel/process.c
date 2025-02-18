#include "process.h"
#include "cpu.h"
#include "memory.h"

void init_process_management(void) {
    // Инициализация управления процессами
    setup_scheduler();
    setup_idle_task();
}

void create_process(void (*start_func)(void)) {
    // Создание нового процесса
    process_t *new_process = allocate_process();
    new_process->start_func = start_func;
    add_process_to_queue(new_process);
}

void schedule(void) {
    // Переключение процессов
    select_next_process();
    context_switch();
}

void terminate_process(process_t *process) {
    // Завершение процесса
    free_process_resources(process);
}
