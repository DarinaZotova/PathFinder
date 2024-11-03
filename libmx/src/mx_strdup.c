#include "../inc/libmx.h"

char *mx_strdup(const char *s1) 
{
    if (!s1) 
    {
        return NULL;
    }

    int length = mx_strlen(s1);
    char *new_str = mx_strnew(length);
    if (!new_str) 
    {
        return NULL;
    }

    mx_strcpy(new_str, s1);
    return new_str;
}
