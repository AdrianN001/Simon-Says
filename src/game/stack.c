#include "simon/game.h"
#include <stdlib.h>
#include <time.h>


stack_t stack_init(void){
    srand(time(NULL));
    stack_t new_stack;
    new_stack.commands = malloc(sizeof(byte_t) * MAX_STACK_SIZE);
    new_stack.pointer = 0;
    return new_stack;
}
void stack_push(stack_t* stack){
    byte_t new_command = (byte_t)(rand() % 4);
    stack->commands[stack->pointer++] = new_command;
}
void stack_free(stack_t* stack){
    free(stack->commands);
}