#include "../inc/libmx.h"

char *mx_strrchr(const char *s, int c) {
    const char *last_occurrence = NULL;

    while (*s) {
        if (*s == (char)c) {
            last_occurrence = s; 
        }
        s++;
    }

    if (c == '\0') {
        return (char *)s; 
    }

    return (char *)last_occurrence; 
}
