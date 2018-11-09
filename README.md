# Data Structure code

## 1. Stack

1. type  
```C
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
```C
STACK* create_stack();
bool push(STACK* stack, void* in);
void* pop(STACK* stack);
```

## 2. Queue
1. type  
```C
typedef struct node {
    void* data_ptr;
    struct node* next;
} QUEUE_NODE;

typedef struct {
    int count;
    QUEUE_NODE* front;
    QUEUE_NODE* rear;
} QUEUE;
```
2. function  
```C
QUEUE* create_queue();
bool enqueue(QUEUE* queue, void* in);
void* dequeue(QUEUE* queue);
```
## 3. Linked List
1. type
```C
typedef struct node {
    void* data_ptr;
    struct node* next;
} NODE;

typedef struct {
    int count;
    NODE* front;
    NODE* rear;
    NODE* pos;
} LLIST;
```
2. function  
```C
LLIST* create_list();
bool add_node_at(LLIST* list, unsigned int index, void* data);
bool del_node_at(LLIST* list, unsigned int index);
```
## 4. Binary Search Tree
1. type
```C
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} T_NODE;

typedef struct {
    int count;
    T_NODE* root;
} BST_TREE;
```
2. function  
```C
BST_TREE* create_bst();

bool BST_insert(BST_TREE* tree, int data);
bool BST_delete(BST_TREE* tree, int data);

T_NODE* add_bst(T_NODE* root, int data);
T_NODE* delete_bst(T_NODE* root, int data, bool* success);
```

HW1 folder has description pdf file for assignment #1

Tutorial folder has scratch code of C language and data structures