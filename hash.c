#include "hash.h"

/*
 * a0 a1 a2 a3 a4 ...
 (a0 + a1 * x + a2 * x^2 + ...) % P
 x -- prime number  ; base
 P -- prime number  ; modulo
 */

static const hash BASE = 187;
static const hash MODULO = 0x5bd1e995;

hash hash_compute(
        const char* str
        ) {
   hash acc = 0;
   for( ; *str ; str++ ) {
     acc *= BASE;
     acc %= MODULO;
     acc += *str;
     acc %= MODULO;
   }
   return acc;
}

