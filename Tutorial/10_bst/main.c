#include "BST_tree.h"
#include <stdio.h>

int main() {
    BST_TREE* tree;
    tree = create_bst();
    if (tree) {
        printf("Create tree success!\n");
    }

    if (BST_insert(tree, 17)) {
        printf("Insert success!\n");
        printf("Tree count: %d\n", tree->count);
    }
    if(!BST_delete(tree, 17)){
        printf("failed on deleting 17 \n");
    }
    else {
        printf("success on deleting 17\n");
    }
    return 0;
}