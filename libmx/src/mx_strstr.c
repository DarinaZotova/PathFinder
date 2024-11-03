#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle)
{
    if (!*needle)
    {
        return (char *)haystack;
    }

    for (const char *h_hay = haystack; *h_hay != '\0'; h_hay++)
        {
        const char *h_step = h_hay;
        const char *n_step = needle;
    
        while(*h_step != '\0' && *n_step != '\0' && *h_step == *n_step)
        {
            h_step++;
            n_step++;
        }

        if(*n_step == '\0')
        {
            return (char *)h_hay;
        }
    }
    return NULL;
}
