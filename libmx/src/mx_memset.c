#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len)
{
    unsigned char *f_ptr = (unsigned char *)b;

    for (size_t i = 0; i < len; i++) 
    {
        f_ptr[i] = (unsigned char )c;
    }
    return b;
}
