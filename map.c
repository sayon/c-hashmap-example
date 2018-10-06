#include "hash.h"
#include "map.h"

#define MAP_SIZE 65537

struct map { struct node* table[MAP_SIZE]; };

struct map* map_create() {
    return calloc(1, sizeof( struct map ) ); 
}

void map_destroy( struct map* m) {
    free( m );
}

void map_add(
        struct map* m,
        const char* key,
        const char* value
        )
{
    size_t idx = hash_compute(key) % MAP_SIZE;

    list_add(
            &( m->table[idx] ),
            (struct entry) { key, value } 
            );
}

const char* map_get(
        struct map* m,
        const char* key 
        ) 
{
    size_t idx = hash_compute(key) % MAP_SIZE;

    struct entry const* const e = list_find_key(
            m->table[idx],
            key 
            ); 

    return e? e->value : NULL;
}
