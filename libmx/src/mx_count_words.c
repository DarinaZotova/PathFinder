#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) 
{
    if (str == NULL) 
    {
        return -1;
    }

    int count = 0;
    int word_inside = 0;

    for (int i = 0; str[i] != '\0'; ++i) 
    {
        if (str[i] == c) 
        {
            word_inside = 0;
        } 
        else 
        {
            if (word_inside == 0) 
            {
                word_inside = 1; 
                ++count; 
            }
        }
    }

    return count;
}
