#include "../inc/libmx.h"

char *mx_file_to_str(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return NULL;  
    }

   
    char buffer[1024];  
    int bytes_read;
    size_t total_size = 0;  
    char *content = NULL;

    
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
       
        total_size += bytes_read;
        
        content = realloc(content, total_size + 1);  
        if (!content) {
            close(fd);
            return NULL;  
        }
       
        for (int i = 0; i < bytes_read; i++) {
            content[total_size - bytes_read + i] = buffer[i];  
        }
    }

    close(fd);

    if (total_size == 0) {
        free(content);
        return NULL;  
    }

    content[total_size] = '\0'; 
    return content;  
}
