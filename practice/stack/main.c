#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ADT_stack.h"

int main(){
    STACK* s1 = create_stack();

    int a = 10;
    int b = 20;

    if (!push(s1, &a))
        printf("error!\n");
    
    if (!push(s1, &b))
        printf("error!\n");

    printf("size of stack is %d\n", s1->count);

    int* temp;
    temp = (int*)pop(s1);

    printf("size of stadk is %d\n", s1->count);
    printf("popped data is %d\n", *temp);


    return 0;
}