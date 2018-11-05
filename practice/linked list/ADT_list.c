#include "ADT_list.h"

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

    NODE* new = (NODE*)malloc(sizeof(NODE));

    if(!new)
        return false;

    new->data_ptr = in;
    new->next = NULL;

    if(list->count == 0){ // 빈 리스트에 add인 경우
        list->front = new;
        list->rear = new;
        (list->count)++;

        return true;
    }

    int iter_i = 0;

    if(index == 0){ // 맨 앞에 add인 경우
        new->next = list->front;
        list->front = new;
        (list->count)++;

        return true;
    }


    if(index == list->count){ //맨 뒤인 경우
        list->rear->next = new;
        list->rear = new;
        (list->count)++;

        return true;
    }

    iter_i++;
    list->pos = list->front;

    while(iter_i != index){
        list->pos = list->pos->next;
        iter_i++;
    }
    
    new->next = list->pos->next;
    list->pos->next = new;
    (list->count)++;

    return true;

}

bool del_node_at(LLIST* list, unsigned int index){
    if(list->count == 0)
        return false;
    else if (index >= list->count)
        return false;

    if(list->count == 1){
        free(list->front);
        list->front = NULL;
        list->rear = NULL;
        list->count = 0; 

        return true;
    }
    NODE* pre = NULL;

    int iter_i = 0;
    list->pos = list->front;

    if(index == 0){
        list->front = list->pos->next;
        free(list->pos);
        list->pos = NULL;
        (list->count)--;

        return true;
    }

    while(iter_i != index){
        pre = list->pos;
        list->pos = list->pos->next;

        iter_i++;
    }

    if(iter_i == list->count){ //맨 마지막 꺼 delete
        
        list->rear = pre;
        list->rear->next = NULL;
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
