#pragma once
#include "simon/def.h"

#define MAX_STACK_SIZE 50

typedef struct {
    byte_t* commands;
    int pointer;
} stack_t;


stack_t stack_init(void);
void stack_push(stack_t* stack);
void stack_free(stack_t* stack);