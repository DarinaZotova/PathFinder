#include "../inc/pathfinder.h"

PathInfo *parse_data(char *file_content){
    // Разбиение данных файла на строки
    char **lines = mx_strsplit(file_content, '\n');
    if (!lines || !lines[0]) {
        mx_printerr("error: file is empty\n");
        mx_del_strarr(&lines);
        return NULL;
    }

    // Парсинг первой строки — количество островов
    char *endptr;
    long island_count_long = mx_strtol(lines[0], &endptr, 10);

    // Проверка, является ли первая строка числом и в пределах допустимого значения
    if (*endptr != '\0' || island_count_long <= 0 || island_count_long > INT_MAX) {
        mx_printerr("error: line 1 is not valid\n");
        mx_del_strarr(&lines);
        return NULL;
    }

    // Парсинг первой строки — количество островов
    if (!mx_is_valid_number(lines[0])){
        mx_printerr("error: line 1 is not valid\n");
        mx_del_strarr(&lines);
        return NULL;
    }

    int island_count_from_file =mx_atoi(lines[0]);  
    if (island_count_from_file <= 0){
        mx_printerr("error: invalid number of islands\n");
        mx_del_strarr(&lines);
        return NULL;
    }

    // Проверка на наличие пустых строк в файле
    for (int i = 1; lines[i]; i++){
        if (mx_strlen(lines[i]) == 0){
            mx_printerr("error: line ");
            mx_printint(i + 1);
            mx_printerr(" is not valid\n");
            mx_del_strarr(&lines);
            return NULL;
        }
    }

    int double_null =mx_get_substr_index(file_content,"\n\n");
    if(double_null != -1 && double_null != mx_strlen(file_content)-1){
        int count =1;
        for(int i = 0; i <= double_null;i++){
            if(file_content[i] == '\n'){
                count++;
            }
        }
        mx_printerr("error: line ");
        mx_printint(count);  
        mx_printerr(" is not valid\n");
        mx_del_strarr(&lines);
        return NULL;
    }

    // Проверка на конец файла (EOF)
    if (file_content[mx_strlen(file_content) - 1] != '\n') {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(mx_arrlen(lines)));  
        mx_printerr(" is not valid\n");
        mx_del_strarr(&lines);
        return NULL;
    }

    // Инициализация структуры PathInfo
    PathInfo *info = (PathInfo *)malloc(sizeof(PathInfo));
    if (!info){
        mx_del_strarr(&lines);
        return NULL;
    }

    info->route_dist = 0;
    info->island_count = 0;
    info->islands = (char **)malloc(sizeof(char *) * island_count_from_file);
    if (!info->islands){
        mx_del_strarr(&lines);
        free(info);
        return NULL;
    }
    info->distances = (long **)malloc(sizeof(long *) * island_count_from_file);
    if (!info->distances){
        mx_del_strarr(&lines);
        free(info->islands);
        free(info);
        return NULL;
    }
    for (int i = 0; i < island_count_from_file; i++){
        info->distances[i] = (long *)malloc(sizeof(long) * island_count_from_file);
        if (!info->distances[i]) {
            free(info->distances);
            free(info->islands);
            free(info);
            mx_del_strarr(&lines);
            return NULL;
        }
        for (int j = 0; j <island_count_from_file;j++) {
            info->distances[i][j] = INT_MAX; 
        }
    }

    // Парсинг строк мостов
    long sum = 0;
    for (int i = 1; lines[i]; i++) {
        if (!parse_bridge_line(lines[i], &info->islands, &info->island_count, info->distances, i + 1, island_count_from_file,&sum)) {
        mx_del_strarr(&lines); 
        for (int j = 0; j < island_count_from_file; j++){
            free(info->distances[j]); 
        }
        free(info->distances);
        for (int j = 0; j < info->island_count;j++){
            mx_strdel(&info->islands[j]); 
        }
        free(info->islands);
        free(info); 
        return NULL; 
        }
    }

    // Проверка на совпадение количества островов
    if (info->island_count != island_count_from_file){
        mx_printerr("error: invalid number of islands\n");
        mx_del_strarr(&lines);
        for (int j =0; j < island_count_from_file; j++){
            free(info->distances[j]);
        }
        free(info->distances);
        free(info->islands);
        free(info);
        return NULL;
    }

    mx_del_strarr(&lines);
    return info;
}
