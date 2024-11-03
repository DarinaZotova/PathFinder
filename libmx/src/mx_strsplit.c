#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c)
{
    int len = mx_strlen(s);
    int res_len = 1;
    if(len == 0)
    {
        char** result = malloc(sizeof(char*)*(1));
        result[0] = NULL;
        return result;
            
    }
    for(int i=0;i<len;i++){
        if(s[i] == c)
        {
            res_len++;
            for(;s[i]==c;i++);
        }
    }

    char** result = malloc(sizeof(char*)*(res_len+1));
    
    for(int i=0;i<res_len+1;i++){
        result[i] = NULL;
    }

    result[res_len] = 0;
    char* start = (char*) s;
    for(;*start == c; start++);
    
    for(int i=start-s,f = 0;i<=len;i++){
        int l = 0;
        if(s[i] == c || i==len){
            l = (s+i) - start;
            result[f] = mx_strndup(start,l);
            for(;s[i]==c;i++);
            start = ((char*)s)+i;
            f++;
        } 
    }
    result[res_len] = NULL;
    return result;
}
