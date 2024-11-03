#include "../inc/libmx.h"

char *mx_strtrim(const char *str) 
{
    if (!str)
        return NULL;

    int len_total = 0;

    while (str[len_total] != '\0') 
    {
        len_total++;
    }

    while (len_total > 0 && mx_isspace(str[len_total - 1])) 
    {
        len_total--;
    }

    int start = 0;
    while (mx_isspace(str[start]) && start < len_total) 
    {
        start++;
    }

    char *dst = mx_strnew(len_total - start);

    if (!dst)
        return NULL;

    for (int i = 0; i < len_total - start; i++) 
    {
        dst[i] = str[start + i];
    }

    return dst;
}
