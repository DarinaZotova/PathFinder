#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) 
{
    if (!str || !sub || !replace || mx_strlen(sub) == 0 || mx_strlen(str) == 0) 
    {
        return NULL;
    }

    int sub_str_len = mx_strlen(sub);
    int replace_str_len = mx_strlen(replace);
    int source_str_len = mx_strlen(str);
    int count_sub = mx_count_substr(str, sub);

    int new_len = source_str_len + (replace_str_len - sub_str_len) * count_sub;

    char *result = mx_strnew(new_len);
    if (!result) 
    {
        return NULL;
    }

    int write_pos = 0;
    int read_pos = 0;

    while (str[read_pos] != '\0') 
    {
        if (mx_strncmp(str + read_pos, sub, sub_str_len) == 0) 
        {
            for (int k = 0; k < replace_str_len; k++) 
            {
                result[write_pos++] = replace[k];
            }
            read_pos += sub_str_len;
        } else 
        {
            result[write_pos++] = str[read_pos++];
        }
    }

    result[write_pos] = '\0';
    return result;
}
