#include "../inc/libmx.h"

long mx_strtol(const char *nptr, char **endptr, int base) {
    const char *p = nptr;
    long result = 0;
    bool negative = false;

    while (*p == ' ') {
        p++;
    }

    if (*p == '-') {
        negative = true;
        p++;
    } else if (*p == '+') {
        p++;
    }

    if (base < 2 || base > 36) {
        if (endptr) {
            *endptr = (char *)nptr; 
        }
        return 0; 
    }

    while (*p != '\0') {
        int digit;

        if (*p >= '0' && *p <= '9') {
            digit = *p - '0';
        } else if (*p >= 'A' && *p <= 'Z') {
            digit = *p - 'A' + 10;
        } else if (*p >= 'a' && *p <= 'z') {
            digit = *p - 'a' + 10;
        } else {
            break; 
        }

        if (digit >= base) {
            break;
        }

        if (result > (LONG_MAX - digit) / base) {
            if (endptr) {
                *endptr = (char *)p; 
            }
            return negative ? LONG_MIN : LONG_MAX; 
        }

        result = result * base + digit;
        p++;
    }

    if (endptr) {
        *endptr = (char *)p;
    }

    return negative ? -result : result; 
}
