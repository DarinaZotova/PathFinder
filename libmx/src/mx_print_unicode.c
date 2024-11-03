#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) 
{
    char out[4];
    int length = 0;

    if (c < 0x80) // Обробка 1б
    {
        out[length++] = (char)c;
    } else if (c < 0x0800) // Обробка символів в межах 2б
    {
        out[length++] = (char)((c >> 6) | 0xC0);
        out[length++] = (char)((c & 0x3F) | 0x80);
    } else if (c < 0x010000) // Обробка 3б
    {
        out[length++] = (char)((c >> 12) | 0xE0);
        out[length++] = (char)(((c >> 6) & 0x3F) | 0x80);
        out[length++] = (char)((c & 0x3F) | 0x80);
    } else if (c < 0x110000) // Обробка 4б
    {
        out[length++] = (char)((c >> 18) | 0xF0);
        out[length++] = (char)(((c >> 12) & 0x3F) | 0x80);
        out[length++] = (char)(((c >> 6) & 0x3F) | 0x80);
        out[length++] = (char)((c & 0x3F) | 0x80);
    }

    write(1, out, length);
}
