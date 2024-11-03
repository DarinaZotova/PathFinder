#include "../inc/libmx.h"

void mx_pop_back(t_list **head) 
{ 
    if (head == NULL || *head == NULL) 
    { 
        return; 
    } 
 
    t_list *i = *head; 
    *head = ((*head)->next == NULL) ? (free(*head), NULL) : *head; 
 
    while (i && i->next && i->next->next != NULL) 
    { 
        i = i->next; 
    } 
 
    if (i && i->next) 
    { 
        free(i->next); 
        i->next = NULL; 
    } 
}
