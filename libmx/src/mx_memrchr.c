#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) 
{
    const unsigned char *buff = (const unsigned char *)s;
    unsigned char key = (unsigned char)c;

    const unsigned char *end = buff + n;

    while (end > buff) 
    {
        if (*(end - 1) == key) 
        {
            return (void *)(end - 1);
        }
        end--;
    }

    return NULL;
}
