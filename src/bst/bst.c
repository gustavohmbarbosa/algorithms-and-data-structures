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

void print_pre_order(Tree root) {
    if (root == NULL) {
        return;
    }

    printf("[%d]", root->value);
    print_pre_order(root->left);
    print_pre_order(root->right);
}

void print_in_order(Tree root) {
    if (root == NULL) {
        return;
    }

    print_in_order(root->left);
    printf("[%d]", root->value);
    print_in_order(root->right);
}

void print_post_order(Tree root) {
    if (root == NULL) {
        return;
    }

    print_post_order(root->left);
    print_post_order(root->right);
    printf("[%d]", root->value);
}

void print_reverse_order(Tree root) {
    if (root == NULL) {
        return;
    }

    print_reverse_order(root->right);
    printf("[%d]", root->value);
    print_reverse_order(root->left);
}
