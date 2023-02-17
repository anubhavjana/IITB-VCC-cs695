
#include "functions.c"
#include <stdio.h>

const char*(*func_pointer[7])(const char*) = {home,square,cube,helloworld,pingpong,prime,fibonacci};