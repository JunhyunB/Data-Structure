#include "list.h"

LLIST* create_list(){
    LLIST* list = (LLIST*)malloc(sizeof(LLIST));

    list->count = 0;
    list->front = NULL;
    list->rear = NULL;
    list->pos = NULL;

    return list;
}

bool add_node_at(LLIST* list, unsigned int index, void* in){
    if(index > list->count)
        return false;
    NODE* new =  (NODE*)malloc(sizeof(NODE));

    new->data_ptr = in;
    new->next = NULL; // 일단은

    if(list->count == 0){
        list->front = new;
        list->rear = new;
        (list->count)++;

        return true;
    }

    int iter_i = 0;
    //맨 앞에 넣는 경우
    if(index == 0){
        new->next = list->front;
        list->front = new;
        (list->count)++;

        return true;
    }
    iter_i ++;
    list->pos = list->front;

    while(iter_i != index){
        list->pos = list->pos->next;
        iter_i++;
    }
    //맨 뒤에 넣는 상황
    if(iter_i == list->count){
        list->pos->next = new;
        list->rear = new;
        (list->count)++;

        return true;
    }
    else{
        new->next = list->pos->next;
        list->pos->next = new;
        (list->count)++;

        return true;
    }

    return false;
}

bool del_node_at(LLIST* list, unsigned int index){
    if(list->count == 0)
        return false;
    else if(index >= list->count)
        return false;

    //노드 하나인 경우
    if(list->count == 1){
        free(list->front);
        list->front = NULL;
        list->rear = NULL;
        list->count = 0;

        return true;
    }

    list->pos = list->front;
    if(index == 0){
        list->front = list->pos->next;
        free(list->pos);
        list->pos = NULL;
        (list->count)--;

        return true;
    }

    int iter_i = 0;
    NODE* pre = NULL;

    while(iter_i != index){
        pre = list->pos;
        list->pos = list->pos->next;
        iter_i++;
    }

    if(index == list->count){
        list->rear = pre;
        pre->next = NULL;
        free(list->pos);
        list->pos = NULL;
        (list->count)--;

        return true;
    }

    else{
        pre->next = list->pos->next;
        free(list->pos);
        list->pos = NULL;
        (list->count)--;

        return true;
    }

    return false;
}

void* read_data(LLIST* list, unsigned int index){

}