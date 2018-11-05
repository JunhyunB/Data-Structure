#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    void* data_ptr;
    struct node* next;
} NODE;

typedef struct {
    int count;
    NODE* front;
    NODE* rear;
} QUEUE;

QUEUE* create_queue();
bool enqueue(QUEUE* queue, void* in);
void* dequeue(QUEUE* queue);