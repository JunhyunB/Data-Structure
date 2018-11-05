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

STACK* create_stack(); // 함수 리턴 값이 STACK!!!
int push(STACK* stack, void* in); // 삽입 대상 STACK , 삽입 할 argument , return 0 : error, return 1 : success
					// void 선언으로 다양한 자료형 넣을 수 있다!!

void* pop(STACK* stack); // pop은 argument가 STACK만 있으면 됨, return 값이 top의 data가 됨


int main() {
	STACK* s1 = create_stack();
	printf("stack s1's size: %d\n", s1->count);

	int a = 10;
	int b = 12;

	push(s1, &a);
	push(s1, &b);

	printf("stack s1's size: %d\n", s1->count);

	int* temp;
	temp = (int*)pop(s1);
	printf("pop: %d\n", *temp);

	printf("stack s1's size: %d\n", s1->count);

}

STACK* create_stack() {
	printf("creating a stack ...\n");
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if ( !stack )
		return 0;

	stack->count = 0;
	stack->top = 0;

	return stack;
}

int push(STACK* stack, void* in) {
	printf("pushing a data into stack ...\n");
	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if ( !node )
		return 0;
	
	node->data_ptr = in;
	node->link = stack->top; // 새로운 스택의 top (my next become old boss)
	stack->top = node; // II am a new boss!
	stack->count++;

	return 1;
}

void* pop(STACK* stack){
	printf("\npopping a data from stack...\n");
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