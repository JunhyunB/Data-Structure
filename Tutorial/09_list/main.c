#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main() {
    LLIST* list1;
    list1 = create_list();

    if(list1 == NULL){
        printf("fail to create linked list\n");
        return -1;
    }
    int a = 10;
    int b = 20;

    if(!add_node_at(list1, 0, a)){
        printf("fail to add node to linked list\n");
    }
    else{
        printf("ok to add node with data %d\n", a);
    }
    return 0;
}