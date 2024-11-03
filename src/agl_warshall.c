#include "../inc/pathfinder.h"

void find_shortest_paths(PathInfo *info) {
    int n = info->island_count;
    info->route_dist=malloc(sizeof(long*)*n);

    for(int i =0; i < n;i++){
        info->route_dist[i]=malloc(sizeof(long)*n);
        mx_memcpy(info->route_dist[i],info->distances[i],sizeof(long)*n);
        info->route_dist[i][i]=0;
    }


    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(info->route_dist[k][j]==INT_MAX){
                    continue;
                }
                long new_dist = info->route_dist[i][k] + info->route_dist[k][j];
                if(new_dist < info->route_dist[i][j]){
                    info->route_dist[i][j]=new_dist;
                }
                
            }
        }
    }
}

