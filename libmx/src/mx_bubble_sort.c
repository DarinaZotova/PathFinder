#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) 
{
    int c_swap= 0;
    for (int x = 0; x < size - 1; x++) 
    { 
        for (int y = 0; y < size - x - 1; y++) 
        {  
            if (mx_strcmp(arr[y], arr[y + 1]) > 0) 
            {           
                char *temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp; 
                c_swap++;
            }
        }
    }
    return c_swap;
}
