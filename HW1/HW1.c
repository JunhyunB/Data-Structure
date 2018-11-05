#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void* data_ptr;
	struct node* link;
}	STACK_NODE;

typedef struct stack {
	int count;
	STACK_NODE* top;
}	STACK;


STACK* create_stack(); 
int push(STACK* stack, void* in); 
void* pop(STACK* stack);

void HW1_1(STACK* s1, STACK* s2);
void HW1_2(STACK* s1, STACK* s2);
void stack_check(STACK* stack);


int main() {
	STACK* s1 = create_stack();
	printf("stack s1 is created...\n");
	STACK* s2 = create_stack();
	printf("stack s2 is created...\n");
	
	int a[5] = {0, 1, 2, 3, 4};
	int b[5] = {5, 6, 7, 8, 9};
	int i, j, s;

	for(i=0;i<(sizeof(a)/sizeof(int));i++){
		push(s1, &a[i]);
	}

	for(j=0;j<(sizeof(b)/sizeof(int));j++){
		push(s2, &b[j]);
	}

	printf("stack s1's size: %d\n", s1->count);
	printf("stack s2's size: %d\n", s2->count);

	printf("\nType 1 or 2 for checking my homework... 1 means HW1_1, 2 means HW1_2\n");
	scanf("%d", &s);

	switch(s){
		case 1 : HW1_1(s1, s2);
		break;
		case 2 : HW1_2(s1, s2);
		break;
	}
	stack_check(s1);
	printf("FIN.\n\n");

}

STACK* create_stack() {
	//printf("creating a stack ...\n");
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if ( !stack )
		return 0;

	stack->count = 0;
	stack->top = 0;

	return stack;
}


int push(STACK* stack, void* in) {

	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if ( !node )
		return 0;
	
	node->data_ptr = in;
	node->link = stack->top; // 새로운 스택의 top (my next become old boss)
	stack->top = node; // II am a new boss!
	stack->count++;

	return 1;
}

void* pop(STACK* stack) {
	//printf("\npopping a data from stack...\n");
	if ( stack->count == 0)
		return 0;
	else{
		STACK_NODE* temp = stack->top;
		void* data_out = stack->top->data_ptr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;

		return data_out;
	}
}

void HW1_1(STACK* s1, STACK* s2) {
	STACK* temp_stack = create_stack();
	//printf("stack for temporary saving is created...\n");
	printf("\nDoing HW1_1...\n");

	int size_temp = s2->count;

	int* temp;

	for(int k=0;k<size_temp;k++){
		temp = (int*)pop(s2);
		push(temp_stack, &(*temp));
	}
	size_temp = temp_stack->count;

	for (int l=0;l<size_temp;l++){
		temp = (int*)pop(temp_stack);
		//printf("pop: %d\n", *temp);
		push(s1, &(*temp));
	}

	printf("stack s1's size: %d\n", s1->count);
}

void HW1_2(STACK* s1, STACK* s2) {
	STACK* temp_stack = create_stack();
	//printf("stack for temporary saving is created...\n");

	printf("\nDoing HW1_2...\n\n");

	int size_temp = s1->count;

	int* temp;

	for(int k=0;k<size_temp-1;k++){
		temp = (int*)pop(s2);
		push(temp_stack, &(*temp));
		temp = (int*)pop(s1);
		push(temp_stack, &(*temp));
	}

	temp = (int*)pop(s2);
	push(s1, &(*temp));

	size_temp = temp_stack->count;

	for (int l=0;l<size_temp;l++){
		temp = (int*)pop(temp_stack);
		//printf("pop: %d\n", *temp);
		push(s1, &(*temp));
	}
	printf("stack s1's size: %d\n", s1->count);
}

void stack_check(STACK* stack) {
	int size_temp = stack->count;

	printf("Final result of the stack s1 is... \n");
	for (int i=0;i<size_temp;i++){
		int* temp;
		temp = (int*)pop(stack);
		printf("%d\n", *temp);
	}
}