#include "../inc/libmx.h"

t_list *mx_create_node(void *data)
{
   t_list* created_node = malloc(sizeof(t_list));
    created_node->data = data;
    created_node->next = 0;
    return created_node;
}
