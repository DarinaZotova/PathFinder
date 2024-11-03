#include "../inc/libmx.h"

char *mx_itoa(int number) 
{
    if (number == 0) 
    {
        char *zero_str = (char *)malloc(2);
        if (zero_str) 
        {
            zero_str[0] = '0';
            zero_str[1] = '\0';
        }
        return zero_str;
    }

    int n = number;
    int length = 0;
    int is_negative = (number < 0);
    
    while (n) 
    {
        n /= 10;
        length++;
    }

    length += is_negative ? 1 : 0;

    char *str = (char *)malloc(length + 1);
    if (!str) 
    {
        return NULL; 
    }
    
    str[length] = '\0'; 

    if (is_negative) 
    {
        str[0] = '-';
        number = -number;
    }

    for (int i = length - 1; number; --i) 
    {
        str[i] = (number % 10) + '0';
        number /= 10;
    }
    
    return str;
}
