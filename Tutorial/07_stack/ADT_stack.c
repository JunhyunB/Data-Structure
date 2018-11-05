#include "ADT_stack.h"

STACK* create_stack(){
    printf("creating a stack...\n");
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    if (!stack)
        return 0;

    stack->count = 0;
    stack->top = 0;

    return stack;
}

bool push(STACK* stack, void* in){
    printf("pushing a data into stack...\n");
    STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    if (!node)
        return 0;

    node->data_ptr = in;
    node->link = stack->top;
    stack->top = node;
    stack->count++;

    return true;
}

void* pop(STACK* stack){
    printf("\npopping a data from stack...\n");
    if (stack->count == 0)
        return 0;
    else{
        STACK_NODE* temp = stack->top;
        void* data_out = stack->top->data_ptr;
        stack->top = stack->top->link;
        free(temp);
        (stack->count)--;

        return data_out;
    }
}