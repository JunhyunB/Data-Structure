#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ADT_list.h"

int main(){
    LLIST* list1 = create_list();

    int a = 10;
    int b = 20;

    if(!add_node_at(list1, 0, &a))
        printf("error\n");

    if(!add_node_at(list1, 1, &b))
        printf("error\n");

    printf("list count : %d\n", list1->count);

    int* temp;
    temp = (int*)read_data(list1, 1);
    printf("data of index 1 is %d\n", *temp);

    del_node_at(list1, 1);

    printf("list count : %d\n", list1->count);
    
    return 0;
}