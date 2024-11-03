#include "../inc/pathfinder.h"

char *read_file(const char *filename){

    int fd = open(filename,O_RDONLY);
    if (fd == -1) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    char buff;
    if (read(fd, &buff, 1)<= 0){
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        close(fd);
        exit(1);
    }
    lseek(fd, 0,SEEK_SET);
    int size = 0;
    while (read(fd,&buff, 1) > 0){
        size++;
    }

    lseek(fd,0,SEEK_SET);
    char *file_content = (char *)malloc(size + 1);
    if (!file_content){
        mx_printerr("error: memory allocation failed\n");
        close(fd);
        exit(1);
    }

    read(fd, file_content,size);
    file_content[size]='\0';

    close(fd);

    return file_content;
}



