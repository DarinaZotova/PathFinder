#include "../inc/pathfinder.h"

// Освобождение массива островов после использования
void free_islands(char **islands, int *island_count) {
    for (int i = 0; i < *island_count; i++){
        mx_strdel(&islands[i]); 
    }
    free(islands); 
}

// Функция для поиска индекса острова в массиве islands
int get_island_index(char **islands, int island_count, const char *island) {
    for (int i = 0; i < island_count; i++) {
        if (islands[i] && mx_strcmp(islands[i], island) == 0) {
            return i;
        }
    }
    return -1;
}

// Добавление нового острова в массив
int add_island(char ***islands, int *island_count, const char *island){
    for (int i = 0; i < *island_count; i++) {
        if (mx_strcmp((*islands)[i], island) == 0) {
            return i;
        }
    }

    

    (*islands)[*island_count] =mx_strdup(island);
    return (*island_count)++;
}

bool parse_bridge_line(char *line, char ***islands, int *island_count, long **distances, int line_number, int max_island_count, long *briges_sum_dist) {

    char **tokens = mx_strsplit(line, '-');
    if (!tokens || !tokens[0] || !tokens[1] ){
        mx_printerr("error: line "); 
        mx_printint(line_number); 
        mx_printerr(" is not valid\n");
        mx_del_strarr(&tokens);
        return false;
    }

    char *island1 = tokens[0];
    char **second_part = mx_strsplit(tokens[1], ',');
    if (!second_part || !second_part[0] || !second_part[1]){
        mx_printerr("error: line "); 
        mx_printint(line_number); 
        mx_printerr(" is not valid\n");
        mx_del_strarr(&tokens);
        mx_del_strarr(&second_part);
        return false;
    }

    char *island2 = second_part[0];
    bool is_valid;
    int distance = mx_atol(second_part[1], &is_valid);
    if (!is_valid || distance <= 0){
        mx_printerr("error: line ");
        mx_printint(line_number);
        mx_printerr(" is not valid\n");
        mx_del_strarr(&tokens);
        mx_del_strarr(&second_part);
        return false;
    }

    if(distance >=INT_MAX){
        mx_printerr("error: sum of bridges lengths is too big\n");
        mx_del_strarr(&tokens);
        mx_del_strarr(&second_part);
        return false;
    }

    // Проверка на совпадение названий островов (путь сам на себя)
    if (mx_strcmp(island1, island2) == 0) {
        mx_printerr("error: line "); 
        mx_printint(line_number); 
        mx_printerr(" is not valid\n");
        mx_del_strarr(&tokens);
        mx_del_strarr(&second_part);
        return false;
    }

    // Исправленная проверка на дефисы
    char *dash = mx_strchr(line, '-');
    if (dash == NULL || *(dash + 1) == '-' || *(dash - 1) == '-' || (dash - line == 0) || (dash - line == mx_strlen(line) - 1)) {
        mx_printerr("error: line "); 
        mx_printint(line_number); 
        mx_printerr(" is not valid\n");
        mx_del_strarr(&tokens);
        mx_del_strarr(&second_part);
        return false;
    }

    // Проверка на только буквы в названиях островов
    for (int i = 0;island1[i] != '\0';i++){
        if (!mx_isalpha(island1[i])) {
            mx_printerr("error: line "); 
            mx_printint(line_number); 
            mx_printerr(" is not valid\n");
            mx_del_strarr(&tokens);
            mx_del_strarr(&second_part);
            return false; 
        }
    }
    for (int i = 0; island2[i] != '\0'; i++){
        if (!mx_isalpha(island2[i])) {
            mx_printerr("error: line "); 
            mx_printint(line_number); 
            mx_printerr(" is not valid\n");
            mx_del_strarr(&tokens);
            mx_del_strarr(&second_part);
            return false; 
        }
    }

    // Проверка на наличие дубликатов пар островов
    for (int i = 0; i < *island_count; i++) {
        if (distances[i] && (mx_strcmp(island1, (*islands)[i]) == 0 || mx_strcmp(island2, (*islands)[i]) ==0)){
            int index = get_island_index(*islands, *island_count, island2);
            if (index != -1 && distances[i][index] != INT_MAX){
                mx_printerr("error: duplicate bridges\n");
                mx_del_strarr(&tokens);
                mx_del_strarr(&second_part);
                return false;
            }
        }
    }

    int index1 = get_island_index(*islands, *island_count, island1);
    int index2 = get_island_index(*islands, *island_count, island2);
    
    

    // Если острова не найдены, добавляем их
    if (index1 == -1) {
        // Проверяем, если добавлено больше островов, чем указано в первой строке
        if (*island_count >= max_island_count) {
            mx_printerr("error: invalid number of islands\n");
            mx_del_strarr(&tokens);
            mx_del_strarr(&second_part);
            return false;
        }
        index1 = add_island(islands, island_count, island1);
    }
    if (index2 == -1) {
        // Проверяем, если добавлено больше островов, чем указано в первой строке
        if (*island_count >= max_island_count) {
            mx_printerr("error: invalid number of islands\n");
            mx_del_strarr(&tokens);
            mx_del_strarr(&second_part);
            return false;
        }
        index2 = add_island(islands, island_count, island2);
    }

    (*briges_sum_dist)+=distance;
    if(*briges_sum_dist < 0 || *briges_sum_dist >INT_MAX){
        mx_printerr("error: sum of bridges lengths is too big\n");
        mx_del_strarr(&tokens);
        mx_del_strarr(&second_part);
        return false;
    }
            
    distances[index1][index2] = distance;
    distances[index2][index1] = distance;

    mx_del_strarr(&tokens);
    mx_del_strarr(&second_part);
    
    return true;
}
