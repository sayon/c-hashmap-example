#!/bin/sh

gcc -std=c11 *.c  -Wall -Werror -o maps
chmod a+x maps
./maps
