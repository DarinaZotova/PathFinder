#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) 
{
    char *initial_dst = dst;
    while (*src)
    {
        *dst++ = *src++;
    }
    *dst = 0;
    return initial_dst;
}
