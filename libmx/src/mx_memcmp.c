#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
 {
    const unsigned char *first_ptr = s1;
    const unsigned char *second_ptr = s2;

    while (n--) 
    {
        if (*first_ptr != *second_ptr) 
        {
            return (*first_ptr > *second_ptr) - (*first_ptr < *second_ptr);
        }
        first_ptr++;
        second_ptr++;
    }

    return 0;
}
