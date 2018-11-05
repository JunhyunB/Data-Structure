#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ADT_stack.h"

int main(){
    STACK* s1 = create_stack();
    printf("stack s1's size %d\n", s1->count);

    int a = 10;
    int b = 12;

    push(s1, &a);
    push(s1, &b);

    printf("stack s1's size: %d\n", s1->count);

    //int* temp;
    //temp = (int*)pop(s1);
    printf("pop :%d\n", *(int*)pop(s1));
   // printf("pop: %d\n", *temp);

    printf("stack s1's size: %d\n", s1->count);

    return 0;
}