#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) 
{
    if (!str)
    {
        return NULL;
    }

    int trimmed_length = 0;
    int i = 0;
    int j = 0;
    int word_active = 0;

    while (str[i] != '\0')
    {
        trimmed_length += !mx_isspace(str[i]) ? (word_active = 1, 1) : (word_active ? (word_active = 0, 1) : 0);
        i++;
    }

    if (trimmed_length == 0)
    {
        return mx_strnew(0);
    }
    
    char *result = mx_strnew(trimmed_length);

    if (!result)
    { 
        return NULL;
    }

    i = 0;
    word_active = 0;
    
    while (str[i] != '\0')
    {
        if (!mx_isspace(str[i]))
        {
            result[j++] = str[i];
            word_active = 1;
        }
        else if (word_active)
        {
            result[j++] = ' ';
            word_active = 0;
        }
        i++;
    }

    if (j > 0 && result[j - 1] == ' ')
    {
      j--;
    }

    result[j] = '\0'; 
    
    return result;
}
