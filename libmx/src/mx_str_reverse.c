#include "../inc/libmx.h"

void mx_str_reverse(char *s)
{
    if(s == NULL || *s == '\0') return;
    int len = mx_strlen(s);
    int index = 0;

    while (index < len / 2)
    {
        mx_swap_char(&s[index], &s[len - 1 - index]);
        index++;
    }
}
