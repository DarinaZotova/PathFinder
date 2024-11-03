#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) 
{
    if (pow == 0) 
    {
        return 1;
    }
    
    double result = 1;
    
    while (pow > 0) 
    {
        if (pow % 2 == 1) 
        {
            result *= n;
        }
        n *= n;
        pow /= 2;
    }
    
    return result;
}
