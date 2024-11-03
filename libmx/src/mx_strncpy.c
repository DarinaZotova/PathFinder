#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) 
{
    
    char *dst_copied = dst;

    while (*src && len--)
    {
        *dst_copied++ = *src++;
    }

    *dst_copied = '\0'; 

    return dst;
}
