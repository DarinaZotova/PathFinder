#include "../inc/libmx.h"

void mx_printint(int n) 
{
    char buffer[12];
    int i = 0;

    if (n == -2147483648) 
    {
        write(1, "-2147483648", 11);
        return;
    }

    if (n < 0) 
    {
        mx_printchar('-');
        n = -n;
    }

    while (n > 0) 
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    if (i == 0) 
    {
        buffer[i++] = '0';
    }

    while (--i >= 0) 
    {
        mx_printchar(buffer[i]);
    }
}
