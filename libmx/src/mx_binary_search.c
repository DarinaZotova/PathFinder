#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) 
{
    int index_s = 0;
    int end_index = size - 1;
    int middle_i;

    if (size <= 0 || !arr || !s) 
    {
        *count = 0;
        return -1;
    }

    while (index_s <= end_index) 
    {
        middle_i = index_s + (end_index - index_s) / 2;
        (*count)++;

        int comparison = mx_strcmp(arr[middle_i], s);
        if (comparison == 0) 
        {
            return middle_i;
        } 
        else if (comparison > 0) 
        {
            end_index = middle_i - 1;
        } 
        else 
        {
            index_s = middle_i + 1;
        }
    }
    
    *count = 0; 
    return -1;
}
