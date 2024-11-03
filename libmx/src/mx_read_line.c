#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) 
{
    if (fd < 0 || buf_size <= 0 || lineptr == NULL) 
    {
        return -2;
    }

    size_t capacity = buf_size; 
    size_t line_size = 0;       

    // виділення пам'яті для рядка
    char *line = (char *)malloc(capacity);
    if (line == NULL) 
    {
        return -2; 
    }
    *lineptr = line;

    char read_char;
    ssize_t bytes_read;

    // читання символів із файлу
    while ((bytes_read = read(fd, &read_char, 1)) > 0) 
    {
        if (read_char == delim) 
        {
            break;
        }

        // якщо буфер переповнений, збільшуємо розмір
        if (line_size >= capacity) 
        {
            capacity *= 2; 
            line = (char *)mx_realloc(*lineptr, capacity);
            if (line == NULL) 
            {
                return -2; 
            }
            *lineptr = line;
        }

        line[line_size++] = read_char;
    }

    if (bytes_read < 0) 
    {
        return -2;
    }

    // завершення рядка / повернення результату
    if (line_size > 0 || bytes_read > 0) 
    {
        line[line_size] = '\0';
        return line_size;       
    } else 
    {
        free(*lineptr);
        *lineptr = NULL;
        return -1;
    }
}
