#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) 
{
    if (!arr || !delim) // Перевірка на NULL
    {
        return;
    }

    char **ptr = arr;

    while (*ptr) // Виведення рядків
    {
        mx_printstr(*ptr);
        ptr++;

        if (*ptr) 
        {
            mx_printstr(delim);
        }
    }

    mx_printchar('\n');
}
