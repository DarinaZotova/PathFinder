#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) 
{
    char *s1_end = s1 + mx_strlen(s1);

    while (*s2) 
    {
        *s1_end++ = *s2++;
    }

    *s1_end = '\0';

    return s1;
}
