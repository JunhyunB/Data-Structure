#include "BST_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    BST_TREE* tree = create_bst();
    BST_TREE* tree_clone;

    if(tree)
        printf("BST created!\n");

    int a[10] = {3, 7, 2, 5, 4, 10, 6, 19, 1, 8};

    for(int i=0;i<(sizeof(a)/sizeof(int));i++) {
		BST_insert(tree, a[i]);
	}

    tree_clone = copy_tree(tree);

    printf("Copy completed!\n");

    return 0;
}