#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) 
{
    if (!str || !sub) 
    {
        return -2;
    }

    int str_length = mx_strlen(str);
    int sub_length = mx_strlen(sub);

    if (sub_length == 0) return 0;

    for (int i = 0; i <= str_length - sub_length; i++) 
    {
        int j;
        for (j = 0; j < sub_length; j++) 
        {
            if (str[i + j] != sub[j]) break;
        }
        if (j == sub_length) return i;
    }

    return -1;
}
