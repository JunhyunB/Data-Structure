#include "BST_tree.h"

BST_TREE* create_bst() {
    BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));
    if(tree) {
        tree->count = 0;
        tree->root = NULL;
        return tree;
    }
    return NULL;
}

bool BST_insert(BST_TREE* tree, int data) {
    T_NODE* newRoot = add_bst(tree->root, data);
    if(newRoot == NULL)
        return false;
    else {
        tree->root = newRoot;
        (tree->count) ++;
        return true;
    }
}

T_NODE* add_bst(T_NODE* root, int data) {
    if(root == NULL){
        T_NODE* newPtr = (T_NODE*)malloc(sizeof(T_NODE));
        newPtr->right = NULL;
        newPtr->left = NULL;
        newPtr->data = data;
        return newPtr;
    }
    if(data < (root->data)) {
        root->left = add_bst(root->left, data);
        return root;
    }
    else {
        root->right = add_bst(root->right, data);
        return root;
    }
}

bool BST_delete() {
    
}

T_NODE* delete_bst() {

}