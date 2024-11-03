#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) 
{
    if (dst == NULL || src == NULL) 
    {
        return NULL;
    }

    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    unsigned char ch = (unsigned char)c;

    for (size_t i = 0; i <= n; i++) 
    {
        *d = *s;
        if (*s == ch) 
        {
            return (void *)(d + 1);
        }
        d++;
        s++;
    }
    *d ='\0';
    return NULL;
}
