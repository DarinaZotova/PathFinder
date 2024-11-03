#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }

    char *file_content =read_file(argv[1]);
    if (file_content == NULL) {
        return 1;
    }

    PathInfo *info =parse_data(file_content);
    free(file_content); 
    if (info == NULL){
        return 1;
    }


    find_shortest_paths(info);

    print_paths(info);

    for (int i = 0; i < info->island_count; i++){
        
        free(info->route_dist[i]);
        free(info->distances[i]);
        free(info->islands[i]);;  
    }

    free(info->islands);
    free(info->route_dist);
    free(info->distances);
    free(info);

    return 0;
}
