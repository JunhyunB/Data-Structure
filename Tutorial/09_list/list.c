#include "list.h"

LLIST* create_list(){
    LLIST* list;
    list = (LLIST*)malloc(sizeof(LLIST));
    if(list){
        list->front = NULL;
        list->rear = NULL;
        list->pos = NULL;
        list->count = 0;
    }
    return list;
}

bool add_node_at(LLIST* list, unsigned int index, void* data) {
    if(index>(list->count))
        return false;
    NODE* node_p;
    node_p = (NODE*)malloc(sizeof(NODE));
    if(!node_p)
        return false;
    node_p->data_ptr = data;
    node_p->next = NULL;
    if(list->count == 0){
        list->front = node_p;
        list->rear = node_p;
        (list->count)++;
        return true;
    }   
    int iter_i = 0;
    if(index == 0){
        node_p->next = list->front;
        list->front = node_p;
        (list->count)++;
        return true;
    }
    iter_i++;
    list->pos = list->front;
    while(iter_i != index){
        list->pos = list->pos->next;
        iter_i++;
    }
    if(iter_i == list->count){
        list->pos->next = node_p;
        list->rear = node_p;
        (list->count)++;
        return true;
    }
    else{
        node_p->next = list->pos->next;
        list->pos->next = node_p;
        (list->count)++;
        return true;
    }
}

bool del_node_at(LLIST* list, unsigned int index){
    if(list->count == 0)
        return false;
    else if(index >= list->count)
        return false;

    if(list->count == 1){
        free(list->front);
        list->front = NULL;
        list->rear = NULL;
        list->count = 0;
        return true;
    }
    int iter_i = 0;
    list->pos = list->front;
    NODE* pre = NULL;
    while(iter_i != index){
        pre = list->pos;
        list->pos = list->pos->next;
        iter_i++;
    }
    if(index == 0){
        list->front = list->pos->next;
        free(list->pos);
        list->pos = NULL;
        (list->count)--;
        return true;
    }
    if(index == (list->count - 1)){
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