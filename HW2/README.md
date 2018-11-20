# HW2

## Implementation for BST functions below.  

**find_smallest_node()** and **find_largest_node()** function find the smallest and the largest node recursively and **search_bst()** function find specific data recursively.  

**traverse_xxxxxxx()** functions traverse Binary Search Tree recursively.  

**copy_tree()** function make clone of specific BST.


```C
T_NODE* find_smallest_node(T_NODE* node);
T_NODE* find_largest_node(T_NODE* node);
T_NODE* search_bst(T_NODE* node, int data);

void traverse_preorder(T_NODE* root);
void traverse_inorder(T_NODE* root);
void traverse_postorder(T_NODE* root);

BST_TREE* copy_tree(BST_TREE* tree);
```