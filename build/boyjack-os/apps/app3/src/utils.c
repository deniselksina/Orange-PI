#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Error handling function
void handle_error(const char *msg) {
    perror(msg);  // Print the error message to stderr
    exit(EXIT_FAILURE);  // Exit the program with failure status
}

// Memory allocation function with error checking
void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        handle_error("Memory allocation failed");
    }
    return ptr;
}

// Function to format a string and return a new dynamically allocated string
char *format_string(const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Allocate initial buffer for formatted string (assume max 256 characters)
    size_t buffer_size = 256;
    char *buffer = safe_malloc(buffer_size);

    int n = vsnprintf(buffer, buffer_size, format, args);

    // If the buffer is not large enough, reallocate and try again
    if (n >= buffer_size) {
        buffer_size = n + 1;
        buffer = realloc(buffer, buffer_size);
        if (buffer == NULL) {
            handle_error("Memory reallocation failed");
        }
        vsnprintf(buffer, buffer_size, format, args);
    }

    va_end(args);
    return buffer;
}

// Simple data cache (global for demonstration purposes)
#define CACHE_SIZE 10
char *data_cache[CACHE_SIZE] = { NULL };

// Cache a string in the global cache
void cache_data(const char *data) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (data_cache[i] == NULL) {
            data_cache[i] = strdup(data);  // Copy data into cache
            return;
        }
    }
    // If cache is full, replace the first entry
    free(data_cache[0]);
    for (int i = 1; i < CACHE_SIZE; i++) {
        data_cache[i - 1] = data_cache[i];
    }
    data_cache[CACHE_SIZE - 1] = strdup(data);
}

// Retrieve data from cache
char *get_cached_data(int index) {
    if (index < 0 || index >= CACHE_SIZE || data_cache[index] == NULL) {
        return NULL;
    }
    return data_cache[index];
}

// Free all cached data
void clear_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        free(data_cache[i]);
        data_cache[i] = NULL;
    }
}

int main() {
    // Example usage of error handling and memory functions
    char *formatted_str = format_string("Hello, %s! You have %d new messages.", "Alice", 5);
    printf("%s\n", formatted_str);
    free(formatted_str);

    // Example usage of the cache system
    cache_data("Cached Data 1");
    cache_data("Cached Data 2");

    char *cached_data = get_cached_data(0);
    if (cached_data != NULL) {
        printf("Retrieved from cache: %s\n", cached_data);
    }

    // Clear the cache before exiting
    clear_cache();

    return 0;
}
