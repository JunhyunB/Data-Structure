#include "BST_tree.h"
#include "ADT_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    printf("-------------------------------------------------\n");
    BST_TREE* tree = create_bst();
    //BST_TREE* tree_clone;
    //QUEUE* queue;
    T_NODE* temp;

    if(tree)
        printf("BST created!\n");

    int a[10] = {7, 3, 2, 5, 4, 10, 6, 19, 1, 8};

    for(int i=0;i<(sizeof(a)/sizeof(int));i++) {
		BST_insert(tree, a[i]);
	}

    //tree_clone = copy_tree(tree, queue);
    temp = search_bst(tree->root, 3);
    printf("search result : %d\n", temp->data);

    return 0;
}