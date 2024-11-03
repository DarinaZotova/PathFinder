#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) 
{
    unsigned long num = nbr;
    int length = 0;

    while (num >= 16)
    {
        length++;
        num /= 16;
    }
    length++;

    char *hex_value = mx_strnew(length);
    if (hex_value == NULL) 
    {
        return NULL; 
    }

    num = nbr;
    for (int i = length - 1; i >= 0; i--)
    {
        unsigned long remainder_value = num % 16;
        if (remainder_value < 10)
            hex_value[i] = (char)(remainder_value + '0');
        else
            hex_value[i] = (char)(remainder_value - 10 + 'a');
        num /= 16;
    }

    return hex_value;
}
