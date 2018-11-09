# Data Structure code

## 1. Stack

1. type
```{.C}
typedef struct node{
    void* data_ptr;
    struct node* link;
} STACK_NODE;

typedef struct stack {
    int count;
    STACK_NODE* top;
} STACK;
```

2. function
```{.C}
STACK* create_stack();
bool push(STACK* stack, void* in);
void* pop(STACK* stack);
```

## 2. Queue
## 3. Linked List
## 4. Binary Search Tree

HW1 folder has description pdf file for assignment #1

Tutorial folder has scratch code of C language and data structures