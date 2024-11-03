#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) 
{
    if (!lst || !cmp) return lst;  
    
    t_list *tmp = lst;
    t_list *created_node = NULL;
    void *new_data;
    int swpd = 1;

    while (swpd) 
    {
        swpd = 0;
        tmp = lst;

        while (tmp->next != NULL) 
        {
            created_node = tmp->next;

            swpd = (cmp(tmp->data, created_node->data)) ? 
                (new_data = tmp->data, tmp->data = created_node->data, created_node->data = new_data, 1) 
                : swpd;

            tmp = tmp->next;
        }
    }

    return lst;
}
