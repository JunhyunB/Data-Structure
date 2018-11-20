# Data Structure code

### **Tutorial** has scratch code of C language and data structures  

### **HW1** has description pdf file for assignment #1  (About **Stack**)
### **[HW2]**  has codes for assignment #2  (About **Binary Search Tree**)  

# Table of Contents  

- [1. Stack](#1-stack-a-namestacka)
    - [1. type of STACK](#1-type-of-stack)
    - [2. function](#2-function)
- [2. Queue](#2-queue)
    - [1. type of QUEUE](#1-type-of-queue)
    - [2. function](#2-function-1)
- [3. Linked List](#3-linked-list)
    - [1. type of Linked List](#1-type-of-linked-list)
    - [2. function](#2-function-2)
- [4. Binary Search Tree](#4-binary-search-tree)
    - [1. type of Binary Search Tree](#1-type-of-binary-search-tree)
    - [2. function](#2-function-3)

## 1. Stack

#### 1. type of STACK  

You shoud consider these types to make **STACK**.  
**STACK_NODE** has void pointer type ***data_ptr*** that points address of data and ***link*** for next node of **STACK**.  
**STACK** has int type ***count*** that indicates the number of nodes in STACK and  
STACK_NODE type ***top*** that indicates the top node of STACK.
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

#### 2. function  

These three functions for STACK were implemented.  
**create_stack()** function creates STACK and initializes it.  
**push() function** 'push' data into the STACK and  
**pop()** function 'pop' data from STACK.  

```C
STACK* create_stack();
bool push(STACK* stack, void* in);
void* pop(STACK* stack);
```

## 2. Queue
#### 1. type of QUEUE  

You should consider these types for **QUEUE**.  
The difference with STACK is that **QUEUE** has components ***front*** and ***rear*** instead of ***top*** of STACK.
***next*** is same with ***link*** of STACK.  

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
#### 2. function  

These three functions for QUEUE were implemented.  
**create_queue()** function creates QUEUE and initializes it.  
**enqueue()** function puts data into the QUEUE and  
**dequeue()** function takes data from the QUEUE and removes the node.  

```C
QUEUE* create_queue();
bool enqueue(QUEUE* queue, void* in);
void* dequeue(QUEUE* queue);
```
## 3. Linked List
#### 1. type of Linked List  

You shoud consider these types to make **Linked List**.  
**NODE** type has same components with STACK or QUEUE, however,  
**LLIST** type has different components of it.  
***count*** indicates the number of nodes in the Linked List, ***front*** indicates the front node of the list, ***rear*** indicates the last node of the list, and, ***pos*** indicates the current position of Linked List.

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
#### 2. function  

These three functions were implemented for Linked List.  
**create_list()** function creates linked list and initializes it.  
**add_node_at()** function add node to the linked list with the index and put the data to it.  
**del_node_at()** function delete node from the linked list with specific index.
```C
LLIST* create_list();
bool add_node_at(LLIST* list, unsigned int index, void* data);
bool del_node_at(LLIST* list, unsigned int index);
```
## 4. Binary Search Tree
#### 1. type of Binary Search Tree  

You shoud consider these types to make **Binary Search Tree**.  
**T_NODE** type has three components, ***data***, ***left***, and ***right***.  
***data*** indicates the data that the node contains, ***left*** indicates the left child of the node, and ***right*** indicates the right child of the node.  
**BST_TREE** type has ***count*** that means the number of nodes in the tree and ***root*** that indicates the root node of the Binary Search Tree.  

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
#### 2. function  
Upper five functions were implemented for Binary Search Tree and others were implemented for assignment.  

**create_bst()** function creates Binary Search Tree and initializes it.  
**BST_insert()** function uses **add_bst()** function to make new node for child and put data into that new node.  
**BST_delete()** function uses **del_bst()** function to delete specific node and remain the tree as Binary Search Tree.

**find_smallest_node()** and **find_largest_node()** function find the smallest and the largest node recursively and **search_bst()** function find specific data recursively.  

**traverse_xxxxxxx()** functions traverse Binary Search Tree recursively.  

**copy_tree()** function make clone of specific BST.

```C
BST_TREE* create_bst();

bool BST_insert(BST_TREE* tree, int data);
T_NODE* add_bst(T_NODE* root, int data);

bool BST_delete(BST_TREE* tree, int data);
T_NODE* delete_bst(T_NODE* root, int data, bool* success);

// ********HOMEWORK 2************
T_NODE* find_smallest_node(T_NODE* node);
T_NODE* find_largest_node(T_NODE* node);
T_NODE* search_bst(T_NODE* node, int data);

void traverse_preorder(T_NODE* root);
void traverse_inorder(T_NODE* root);
void traverse_postorder(T_NODE* root);

BST_TREE* copy_tree(BST_TREE* tree);
```

[HW2] : https://github.com/JunhyunB/Data-Structure/blob/master/HW2/README.md
