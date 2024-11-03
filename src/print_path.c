#include "../inc/pathfinder.h"


t_list* find_pathes(PathInfo* info,int start, int end, int* cur, int path_index){
    int end_path = cur[path_index];
    if(end_path==end){
        int *buf = malloc(sizeof(int)*(info->island_count+1));
        mx_memcpy(buf,cur,sizeof(int)*(info->island_count+1));
        t_list* res = 0;
        mx_push_front(&res,buf);
        return res;
    }
    t_list* res = 0;
    for(int i = 0; i < info->island_count;i++) {
        int a =0;
        bool temp = false;
        if(i == end_path){
            continue;
        }
        while(cur[a]!=-10){
            if(cur[a]==i){
                temp = true;
                break;
            }

            a++;
        }
        if(temp){
            continue;
        }
        int unit_dist = info->distances[end_path][i];
        if(unit_dist ==INT_MAX){
            continue;
        }
        int to_end_index = info->route_dist[i][end];
        if(to_end_index==INT_MAX){
            continue;
        }
        int start_index_to =unit_dist;
        a=0;
        while (cur[a+1]!=-10){
            start_index_to += info->distances[cur[a]][cur[a+1]];
            a++;            
        }
        int full_dist = to_end_index + start_index_to;
        if(full_dist != info->route_dist[start][end]){
            continue;
        }
        t_list *res_an = 0;
        int* buf = malloc(sizeof(int) * (info->island_count+1));
        mx_memcpy(buf,cur,sizeof(int) * (info->island_count+1));
        buf[path_index+1]=i;
        res_an = find_pathes(info,start,end,buf,path_index+1);
        free(buf);
        while(res_an!=0){
            int* path = res_an->data;
            mx_push_back(&res,path);
            mx_pop_front(&res_an);
        }
    }
    return res;
}

void print_paths(PathInfo *info){
    int n = info->island_count;

    for (int start = 0; start < n; start++){
        for (int end = start + 1; end < n; end++){
            if (info->route_dist[start][end] == INT_MAX) continue;
            int *cur = malloc((info->island_count + 1) * sizeof(int));
            for(int i =0;i<(info->island_count+1);i++){
                cur[i]=-10;
            }
            cur[0]= start;

            t_list* pathes = find_pathes(info,start,end,cur,0);
            free(cur);
            
            while (pathes!=0)
            {
                int* route = pathes->data;
                mx_printstr("========================================\n");
                mx_printstr("Path: ");
                mx_printstr(info->islands[start]);
                mx_printstr(" -> ");
                mx_printstr(info->islands[end]);
                mx_printchar('\n');

                mx_printstr("Route: ");
                for (int i =0; route[i]!=-10;i++){
                    mx_printstr(info->islands[route[i]]);
                    if (route[i +1]!=-10) {
                        mx_printstr(" -> ");
                    }
                }
                mx_printchar('\n');

                mx_printstr("Distance: ");
                if (route[2] == -10){
                    mx_printint(info->distances[route[0]][route[1]]);
                }
                else{
                    int full_dist =0;
                    for (int i =0; route[i+1]!= -10; i++) {
                        int interval =info->distances[route[i]][route[i +1]];
                        full_dist += interval;
                        mx_printint(interval);
                        if (route[i +2]!=-10) {
                            mx_printstr(" + ");
                        }
                    }
                    mx_printstr(" = ");
                    mx_printint(full_dist);
                }
                mx_printstr("\n========================================\n");

                free(pathes->data);
                mx_pop_front(&pathes);

            }
            
        }
    }
}
