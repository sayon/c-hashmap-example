#pragma once
#include <stdlib.h>

struct entry {
    const char* key;
    const char* value;
};

struct node {
    struct entry value; 
    struct node* next;
};

void list_add(
       struct node** list,
       struct entry elem
       );

struct entry* list_find(
       struct node* list,
       int predicate(struct entry*)
       );

struct entry* list_find_key(
       struct node* list,
       const char* key
       );
