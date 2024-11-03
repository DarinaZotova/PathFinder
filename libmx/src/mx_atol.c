#include "../inc/libmx.h"


int mx_atol(const char *str, bool *is_valid) {
    long long result = 0;
    int sign = 1;
    *is_valid = true;  

    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r') {
        str++;
    }

    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');

            if (result > INT_MAX && sign == 1) {
                *is_valid = false;  
                return 0;
            } else if (-result < INT_MIN && sign == -1) {
                *is_valid = false;  
                return 0;
            }
        } else {
            *is_valid = false;  
            return 0;
        }
        str++;
    }

    return (int)(sign * result);
}
