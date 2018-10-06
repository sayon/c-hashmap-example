#pragma once

#include "list.h"

// opaque struct
struct map;

struct map* map_create();
void map_destroy( struct map* m );

void map_add(
        struct map* m,
        const char* key,
        const char* value
        );

const char* map_get(
        struct map* m,
        const char* key
        );
