#pragma once

#include "../libmx/inc/libmx.h"
#include <stdio.h> 


#define INT_MAX 2147483647 
#define MAX_ISLANDS 100 
#define BUF_SIZE 1024


// Основная структура PathInfo для хранения всех данных
typedef struct {
    int island_count;   // Количество островов
    char **islands;     // Массив названий островов
    long **distances;    // Матрица расстояний между островами
    long **route_dist;    //матрица расстояний
} PathInfo;

//read file
char *read_file(const char *filename);

// parse_data
PathInfo *parse_data(char *file_content);

// validation
int get_island_index(char **islands, int island_count, const char *island);
int add_island(char ***islands, int *island_count, const char *island);
bool parse_bridge_line(char *line, char ***islands, int *island_count, long **distances, int line_number, int max_island_count, long *briges_sum_dist);


//floyd_warshall
void find_shortest_paths(PathInfo *info);


//print_shortest_paths
void print_paths(PathInfo *info);
t_list* find_pathes(PathInfo* info,int start, int end, int* cur, int path_index);
