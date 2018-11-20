#include "BST_tree.h"
#include "ADT_queue.h"

BST_TREE* create_bst() {
    BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));
    if(tree) {
        tree->root = NULL;
        tree->count = 0;
        return tree;
    }
    return NULL;
}

bool BST_insert(BST_TREE* tree, int data) {
    T_NODE* newRoot;
    newRoot = add_bst(tree->root, data);
    if(newRoot == NULL)
        return false;
    else {
        tree->root = newRoot;
        (tree->count)++;
        //printf("%d is inserted!\n", data);
        return true;
    }
}

T_NODE* add_bst(T_NODE* root, int data) {
    if(root == NULL) { 
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

bool BST_delete(BST_TREE* tree, int data) {
    bool success;
    T_NODE* newRoot;
    newRoot = delete_bst(tree->root, data, &success);
    if(success) {
        tree->root = newRoot;
        (tree->count)--;
        if(tree->count == 0)
            tree->root = NULL;
    }
    return success;
}

T_NODE* delete_bst(T_NODE* root, int data, bool* success) {
    *success = false;
    T_NODE* newRoot;
    T_NODE* deleted_node;
    T_NODE* search;

    if(root == NULL) {
        *success = false;
        return NULL;
    }
    //traverse
    if(data < (root->data)) { //exist at left somewhere
        root->left = delete_bst(root->left, data, success);
    }

    else if(data > (root->data)) { //exist at right somewhere
        root->right = delete_bst(root->left, data, success);
    }
    else { //matched
        deleted_node = root;
        if (root->left == NULL) { //case(1)
            newRoot = root->right;
            free(deleted_node);
            *success = true;
            return newRoot;
        }
        else{ //case(2)
            if(root->right == NULL) {
                newRoot = root->left;
                free(deleted_node);
                *success = true;
                return newRoot;
            }
            else{ //case(3) : I have two slaves
                search = root->left;
                while(search->right != NULL)
                    search = search->right;
                root->data = search->data; //Promotion!
                root->left = delete_bst(root->left, search->data, success);
                // promote 되었으니 원래 위치에서 삭제해야함!
            }
        }
    }
    return root;
}

T_NODE* find_smallest_node(T_NODE* root) {
    if(root->left == NULL)
        return root;
    else
        return find_smallest_node(root->left);
}

T_NODE* find_largest_node(T_NODE* root) {
    if(root->right == NULL)
        return root;
    else
        return find_largest_node(root->right);
}

T_NODE* search_bst(T_NODE* root, int key) {
    if(root == NULL)
        return NULL;
    if(key < (root->data))
        root->left = search_bst(root->left, key);
        //return search_bst(root->left, key);
    else if(key > (root->data))
        root->right = search_bst(root->right, key);
        //return search_bst(root->right, key);
    else
        return root;
}

void traverse_preorder(T_NODE* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}
void traverse_postorder(T_NODE* root) {
    if(root != NULL) {
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("%d ", root->data);

    }
}
void traverse_inorder(T_NODE* root) {
    if(root != NULL) {
        traverse_inorder(root->left);
        printf("%d ", root->data);
        traverse_inorder(root->right);
    }
}

BST_TREE* copy_tree(BST_TREE* tree) {
    return NULL;
    /*
    T_NODE* temp = tree->root;

    if(temp != NULL) {
        enqueue(queue, &(temp->data));
        tree->root = temp->left;
        copy_tree(tree, queue);
        tree->root = temp->right;
        copy_tree(tree, queue);
   }
   if(queue->count == tree->count) {
        BST_TREE* tree_clone = create_bst();
        printf("copying...\n");
        bool check = BST_insert(tree_clone, *(int*)dequeue(queue));
        return tree_clone;
   }
   return NULL;
   */
}