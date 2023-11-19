#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void tree_insert(Tree *root, int value) {
    if (*root == NULL) {
        *root = (Tree) malloc(sizeof(Node)); 
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->value = value;
        return;
    }

    if (value > (*root)->value) {
        return tree_insert(&(*root)->right, value);
    }

    return tree_insert(&(*root)->left, value);
}

void _print_pre_order(Tree root) {
    if (root == NULL) {
        return;
    }

    printf("[%d]", root->value);
    _print_pre_order(root->left);
    _print_pre_order(root->right);
}

void tree_print_pre_order(Tree root) {
    _print_pre_order(root);
    printf("\n");
}

void _print_in_order(Tree root) {
    if (root == NULL) {
        return;
    }

    _print_in_order(root->left);
    printf("[%d]", root->value);
    _print_in_order(root->right);
}

void tree_print_in_order(Tree root) {
    _print_in_order(root);
    printf("\n");
}

void _print_post_order(Tree root) {
    if (root == NULL) {
        return;
    }

    _print_post_order(root->left);
    _print_post_order(root->right);
    printf("[%d]", root->value);
}

void tree_print_post_order(Tree root) {
    _print_post_order(root);
    printf("\n");
}

void _print_reverse_order(Tree root) {
    if (root == NULL) {
        return;
    }

    _print_reverse_order(root->right);
    printf("[%d]", root->value);
    _print_reverse_order(root->left);
}

void tree_print_reverse_order(Tree root) {
    _print_reverse_order(root);
    printf("\n");
}

int tree_even_amount(Tree root) {
    if (root == NULL) {
        return 0;
    }

    int result = tree_even_amount(root->left) + tree_even_amount(root->right);
    if (root->value % 2 == 0) {
        result++;
    }

    return result;
}

int tree_predecessor(Tree root, int value) { // TODO: try to do with "reverse order"
    int result = value;
    
    Tree temp = root;
    int has_value = 0;
    while (temp != NULL) {
        if (temp->value < value) {
            if (temp->value > result || result == value) {
                result = temp->value;
            }

            temp = temp->right;
            continue;
        }

        if (temp->value > value) {
            temp = temp->left;
            continue;
        }

        if (temp->value == value) {
            has_value = 1;
            temp = temp->left;
            continue;
        }

        break;
    }

    return (has_value && result != value) ? result : -1;
}

int find_parent(Tree root, int value, int tree_parent) {
    if (root == NULL) {
        return -1;
    }

    if (root->value > value) {
        return find_parent(root->left, value, root->value);
    }

    if (root->value < value) {
        return find_parent(root->right, value, root->value);
    }

    return tree_parent;
}

int tree_parent(Tree root, int value) {
    if (root == NULL || root->value == value) {
        return -1;
    }
 
    return find_parent(root, value, value);
}

int tree_exists(Tree root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (root->value == value) {
        return 1;
    }

    if (value > root->value) {
        return tree_exists(root->right, value);
    }

    if (value < root->value) {
        return tree_exists(root->left, value);
    }

    return 0;
}

void tree_remove(Tree *root, int value) {
    if (*root == NULL) {
        return;
    }

    if (value > (*root)->value) {
        return tree_remove(&(*root)->right, value);
    }

    if (value < (*root)->value) {
        return tree_remove(&(*root)->left, value);
    }

    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
        return;
    }

    if ((*root)->left == NULL) {
        Tree temp = (*root)->right;
        *root = temp;
        free((*root)->right);
        return;
    }

    if ((*root)->right == NULL) {
        Tree temp = (*root)->left;
        *root = temp;
        free((*root)->left);
        return;
    }

    Tree *inorder_successor = &(*root)->right;
    while ((*inorder_successor)->left != NULL) {
        inorder_successor = &(*inorder_successor)->left;
    }

    (*root)->value = (*inorder_successor)->value;
    free(*inorder_successor);
    *inorder_successor = NULL;
}

int tree_even_sum(Tree root) {
    if (root == NULL) {
        return 0;
    }
    int value = (root->value % 2) == 0 ? root->value : 0;

    return value + tree_even_sum(root->left) + tree_even_sum(root->right);
}
