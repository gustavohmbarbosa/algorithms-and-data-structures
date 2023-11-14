#ifndef BST_H
#define BST_H

typedef struct Node {
    int value;
    struct Node *right;
    struct Node *left;
} Node;

typedef Node *Tree;

void insert(Tree *root, int value);

void print_pre_order(Tree root);

void print_in_order(Tree root);

void print_post_order(Tree root);

void print_reverse_order(Tree root);

int even_amount(Tree root);

#endif