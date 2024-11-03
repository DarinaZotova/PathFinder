#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) 
{
    size_t str_len = mx_strlen(s1);
    
    if (n > str_len) 
    {
        n = str_len;
    }

    char *str_new = mx_strnew(n);
    if (!str_new) 
    {
        return NULL;
    }

    mx_strncpy(str_new, s1, n);
    
    return str_new;
}
