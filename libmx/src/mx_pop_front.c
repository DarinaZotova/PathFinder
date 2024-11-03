#include "../inc/libmx.h"

void mx_pop_front(t_list **head)
{
    t_list *i = (head && *head) ? *head : NULL; 
    
    if (!i) return; 

    if ((*head)->next == NULL) 
    { 
        free(*head); 
        *head = NULL; 

    } else 
    { 
        t_list *i = *head; 
        *head = (*head)->next; 
        free(i); 
    }
}
