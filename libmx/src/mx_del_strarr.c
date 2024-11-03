#include "../inc/libmx.h"

void mx_del_strarr(char ***arr)
{
    char **dst = *arr;
    
    if (dst) 
    {
        while (*dst) 
        {
            mx_strdel(dst++);
        }
        free(*arr);
        *arr = NULL;
    }
}
