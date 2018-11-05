#include "ADT_queue.h"

QUEUE* create_queue(){
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));

    if(queue){
        queue->count = 0;
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

bool enqueue(QUEUE* queue, void* in){
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data_ptr = in;
    new->next = NULL;

    if(queue->count == 0){
        queue->front = new;
        queue->rear = new;
        (queue->count)++;

        return true;
    }

    else{
        queue->rear->next = new;
        queue->rear = new;
        (queue->count)++;
        
        return true;
    }

    return false;
}

void* dequeue(QUEUE* queue){
    if(queue->count == 0)
        return NULL;

    NODE* temp = queue->front;
    void* data_out = queue->front->data_ptr;

    if(queue->count == 1){
        queue->front = NULL;
        queue->rear = NULL;
    }
    else{
        queue->front = queue->front->next;
    }
    free(temp);
    (queue->count)--;

    return data_out;
}