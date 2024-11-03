#include "../inc/libmx.h"

int mx_arrlen(char **arr) {
    int length = 0;
    while (arr[length] != NULL) {
        length++;
    }
    return length;
}
