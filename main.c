#include <stdio.h>

#include "map.h"

void entry_print( struct entry* e) {
    printf("(%s; %s)\n", e->key, e->value);
}

void test_lists () {
    struct node* list = NULL;
    struct entry elem = { "coq", "mastah" };
    list_add( &list, elem );
    struct entry elem2 = { "asm", "meister" };
    list_add( &list, elem2 );

    entry_print( 
            list_find_key( list, "coq") 
            );
    entry_print( 
            list_find_key( list, "asm") 
            );
}

void test_maps() {
    struct map* m = map_create();

    map_add( m, "coq", "master" );
    map_add( m, "asm", "very master" );

    puts( map_get( m, "asm" ) );
    puts( map_get( m, "coq" ) );
    map_destroy( m );
}

int main() {
    //test_lists();
    test_maps(); 
    return 0; 
}
