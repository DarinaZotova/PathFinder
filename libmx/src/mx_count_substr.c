#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) 
{
    if (!str || !sub) 
    {
        return -1;
    }

    int substr_len  = mx_strlen(sub);
    int count = 0;

    if (substr_len  == 0) 
    {
        return 0;
    }

    while (*str) 
    {
        const char *s = str;
        const char *p = sub;

        while (*s && *p && *s == *p) 
        {
            s++;
            p++;
        }

        if (!*p) 
        {
            count++;
            str = s;
        } else 
        {
            str++;
        }
    }

    return count;
}
