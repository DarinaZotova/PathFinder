#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) 
{
    unsigned char *d = dst;
    const unsigned char *s = src;

    if (d < s) 
    {
        while (len--) 
        {
            *d++ = *s++;
        }
    } else 
    {
        const unsigned char *s_end = s + (len - 1);
        unsigned char *d_end = d + (len - 1);
        while (len--) 
        {
            *d_end-- = *s_end--;
        }
    }
    return dst;
}
