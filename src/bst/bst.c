#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void insert(Tree *root, int value) {
    if (*root == NULL) {
        *root = (Tree) malloc(sizeof(Node)); 
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->value = value;
        return;
    }

    if (value > (*root)->value) {
        return insert(&(*root)->right, value);
    }

    return insert(&(*root)->left, value);
}


void _print_pre_order(Tree root) {
    if (root == NULL) {
        return;
    }

    printf("[%d]", root->value);
    _print_pre_order(root->left);
    _print_pre_order(root->right);
}

void print_pre_order(Tree root) {
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

void print_in_order(Tree root) {
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

void print_post_order(Tree root) {
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

void print_reverse_order(Tree root) {
    _print_reverse_order(root);
    printf("\n");
}

int even_amount(Tree root) {
    if (root == NULL) {
        return 0;
    }

    int result = even_amount(root->left) + even_amount(root->right);
    if (root->value % 2 == 0) {
        result++;
    }

    return result;
}

int predecessor(Tree root, int value) {
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


int find_parent(Tree root, int value, int parent) {
    if (root == NULL) {
        return -1;
    }

    if (root->value > value) {
        return find_parent(root->left, value, root->value);
    }

    if (root->value < value) {
        return find_parent(root->right, value, root->value);
    }

    return parent;
}

int parent(Tree root, int value) {
    if (root == NULL || root->value == value) {
        return -1;
    }
 
    return find_parent(root, value, value);
}

int exists(Tree root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (root->value == value) {
        return 1;
    }

    if (value > root->value) {
        return exists(root->right, value);
    }

    if (value < root->value) {
        return exists(root->left, value);
    }

    return 0;
}
