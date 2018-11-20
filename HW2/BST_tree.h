#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} T_NODE; // Atomic NOde

typedef struct {
    int count;
    T_NODE* root;
} BST_TREE; // Tree Top DS

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