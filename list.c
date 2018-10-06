#include <stdlib.h>
#include <string.h>

#include "list.h"

void list_add(
       struct node** list,
       struct entry elem
       )
{
    struct node* newelem = 
        malloc( sizeof( struct node) );
    newelem->value = elem;
    newelem->next = *list;
    *list = newelem; 
}

struct entry* list_find(
       struct node* list,
       int predicate(struct entry*)
       ) 
{
    for (; list; list = list->next) {
        struct entry* current = &(list->value);
        if (predicate ( current ) )
            return current; 
    } 
    return NULL;
}

struct entry* list_find_key(
       struct node* list,
       const char* key
       ) 
{
    for (struct node* n = list; n; n = n->next) {
        struct entry* const current = & n->value;
        if (strcmp(current->key, key) == 0)
            return current; 
    } 
    return NULL;
}
