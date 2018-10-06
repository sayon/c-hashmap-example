#pragma once

#include <stdint.h>

typedef uint64_t hash;

hash hash_compute( const char* str );
