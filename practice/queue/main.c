#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ADT_queue.h"

int main(){
    QUEUE* q1 = create_queue();

    int a = 10;
    int b = 20;

    if(!enqueue(q1, &a))
        printf("error\n");

    if(!enqueue(q1, &b))
        printf("error\n");

    printf("queue count is %d\n", q1->count);

    int* temp;
    temp = (int*)dequeue(q1);

    printf("dequeued data is %d\n", *temp);

    temp = (int*)dequeue(q1);

    printf("dequeued data is %d\n", *temp);

    return 0;
}