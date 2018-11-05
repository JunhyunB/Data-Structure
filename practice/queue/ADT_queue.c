#include "ADT_queue.h"

QUEUE* create_queue(){
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));

    if (queue){
        queue->count = 0;
        queue->front = NULL;
        queue-> rear = NULL;

        return queue;
    }

    else
        return NULL;
}

bool enqueue(QUEUE* queue, void* in){
    QUEUE_NODE* new_node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

    new_node->data_ptr = in;
    new_node->next = NULL;

    if (queue->count == 0){
        queue->front = new_node;
        queue->rear = new_node;
        (queue->count)++;
    }
    
    else{
        queue->rear->next = new_node;
        queue->rear = new_node;
        (queue->count)++;
    }
    return true;
}

void* dequeue(QUEUE* queue){
    if(queue->count == 0)
        return NULL;
    QUEUE_NODE* temp = queue->front;
    void* data_out = queue->front->data_ptr;

    if(queue->count==1){
        queue->front = NULL;
        queue->rear = NULL;
    }
    else{
        queue->front = queue->front->next;
    }
    (queue->count)--;
    free(temp);

    return data_out;
}