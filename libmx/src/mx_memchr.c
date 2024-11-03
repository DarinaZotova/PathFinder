#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) 
{
    unsigned char *buff = (unsigned char *)s;
    unsigned char key = (unsigned char)c;
    size_t len = n;

    while (len--) 
    {
        if (*buff == key) 
        {
            return (void *)buff;
        }
        buff++;
    }
    return NULL;
}
