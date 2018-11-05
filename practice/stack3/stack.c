#include "stack.h"

STACK* create_stack(){
    STACK* stack = (STACK*)malloc(sizeof(STACK));

    stack->count = 0;
    stack->top = NULL;

    return stack;
}

bool push(STACK* stack, void* in){
    NODE* new = (NODE*)malloc(sizeof(NODE));

    if(!new)
        return false;

    new->data_ptr = in;
    new->next = stack->top;
    stack->top = new;
    (stack->count)++;

    return true;
}

void* pop(STACK* stack){
    if(stack->count == 0)
        return NULL;

    NODE* temp = stack->top;
    void* data_out = stack->top->data_ptr;
    stack->top = stack->top->next;
    free(temp);
    (stack->count)--;

    return data_out;
}