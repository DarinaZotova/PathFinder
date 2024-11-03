#include "../inc/libmx.h"

void *mx_calloc(size_t count, size_t size) {
    size_t total_size = count * size;

    void *ptr = malloc(total_size);

    if (!ptr) {
        return NULL;
    }

    mx_memset(ptr, 0, total_size);

    return ptr;
}
