#include "../inc/libmx.h"

// Функция для проверки, является ли строка числом
int mx_is_valid_number(const char *str) {
    if (*str == '0') {
        return 0; 
    }
    
    while (*str) {
        if (!mx_isdigit(*str)) {
            return 0; 
        }
        str++;
    }
    return 1;
}
