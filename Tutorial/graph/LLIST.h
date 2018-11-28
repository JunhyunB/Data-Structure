#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct l_node {
    void* data_ptr;
    struct l_node* next;
} NODE;

typedef struct {
    int count;
    NODE* front;
    NODE* rear;
    NODE* pos;
} LLIST;

LLIST* create_list();
bool add_node_at(LLIST* list, unsigned int index, void* data);
bool del_node_at(LLIST* list, unsigned int index);
//LLIST* reverse_list(LLIST* list);