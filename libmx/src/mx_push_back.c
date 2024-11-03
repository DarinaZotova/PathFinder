#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) 
{
    t_list *created_node = (list && (created_node = mx_create_node(data))) ? created_node : NULL;
    if (!created_node) return; 

    if (*list == NULL) 
    {
        *list = created_node;

    } else 
    {
        t_list *i = *list;
        while (i->next != NULL) 
        {
            i = i->next;
        }
        i->next = created_node;
    }

}
