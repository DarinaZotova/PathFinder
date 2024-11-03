#include "../inc/libmx.h"

void mx_swap_char(char *s1, char *s2) 
{
    if (s1 == NULL || s2 == NULL) 
    {
        return;
    }

    char s1_temp = *s1;
    char s2_temp = *s2;
    *s1 = s2_temp;
    *s2 = s1_temp;
}
