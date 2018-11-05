#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // gcc 로도 bool 가능

typedef struct node { // 구조체 안에서 자기 자신 재귀적 호출 -> 이름 필요
    void* data_ptr;
    struct node* next;
} QUEUE_NODE;

typedef struct { // 구조체 이름 안써도 괜찮음 ㅎㅎ
    int count;
    QUEUE_NODE* front;
    QUEUE_NODE* rear;
} QUEUE;

QUEUE* create_queue();
bool enqueue(QUEUE* queue, void* in);
void* dequeue(QUEUE* queue); // data_ptr을 return!!