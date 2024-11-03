#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) 
{
    if (!hex) 
    {
        return 0; 
    }

    unsigned long num_result = 0;

    for (; *hex != '\0'; hex++) // проходимо по кожному символу рядка
    {
        unsigned long value_current;

        if (*hex >= '0' && *hex <= '9') 
        {
            value_current = *hex - '0'; 
        }
        else if (*hex >= 'A' && *hex <= 'F') 
        {
            value_current = *hex - 'A' + 10; 
        }
        else if (*hex >= 'a' && *hex <= 'f') 
        {
            value_current = *hex - 'a' + 10; 
        }
        else 
        {
            return 0; 
        }

        num_result = num_result * 16 + value_current; 
    }

    return num_result; 
}
