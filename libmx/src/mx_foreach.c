#include "../inc/libmx.h"

void mx_foreach(int *arr, int size, void (*f)(int)) 
{
    if (size <= 0 || !arr || !f) 
    {
        return; 
    }

    int i = 0;
    do 
    {
        f(arr[i]); 
        i++;
    } while (i < size);  
}
