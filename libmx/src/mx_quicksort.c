#include "../inc/libmx.h"

int swap_sort(char** arr, int left, int right, int* swaps_count) 
{
    char* middle = arr[left + (right - left) / 2];  

    int i = left;
    int j = right;

    while (i <= j) 
    {
        
        while (mx_strlen(arr[i]) < mx_strlen(middle)) 
        {
            i++;
        }
        
        while (mx_strlen(arr[j]) > mx_strlen(middle)) 
        {
            j--;
        }

        if (i <= j) 
        {
            if (i != j && mx_strlen(arr[i]) != mx_strlen(arr[j])) 
            {  
                char* tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                (*swaps_count)++;  
            }
            i++;
            j--;
        }
    }

    return i; 
}


int mx_quicksort(char** arr, int left, int right) 
{
    if (arr == NULL) 
    {
        return -1; 
    }

    int swaps_count = 0;

    if (left < right) 
    {
        
        int partition_index = swap_sort(arr, left, right, &swaps_count);

       
        if (left < partition_index - 1) 
        {
            swaps_count += mx_quicksort(arr, left, partition_index - 1);
        }

        
        if (partition_index < right) 
        {
            swaps_count += mx_quicksort(arr, partition_index, right);
        }
    }

    return swaps_count;

}
