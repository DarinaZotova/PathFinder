#include "../inc/libmx.h"

void mx_sort(void *arr, int left, int right, int size, int (*cmp)(const void *, const void *)) {
    if (left >= right) return;

    // Используем pivot для разбиения массива
    char *array = (char *)arr;
    char *pivot = array + left * size;
    int l = left + 1;
    int r = right;

    while (l <= r) {
        while (l <= right && cmp(array + l * size, pivot) < 0) l++;
        while (r >= left && cmp(array + r * size, pivot) > 0) r--;
        if (l < r) {
            // Обмен элементов
            for (int i = 0; i < size; i++) {
                char temp = array[l * size + i];
                array[l * size + i] = array[r * size + i];
                array[r * size + i] = temp;
            }
            l++;
            r--;
        }
    }

    // Обмен pivot с элементом в позиции r
    for (int i = 0; i < size; i++) {
        char temp = array[left * size + i];
        array[left * size + i] = array[r * size + i];
        array[r * size + i] = temp;
    }

    // Рекурсивно сортируем левую и правую часть
    mx_sort(arr, left, r - 1, size, cmp);
    mx_sort(arr, r + 1, right, size, cmp);
}
