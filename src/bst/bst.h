#ifndef BST_H
#define BST_H

typedef struct Node {
    int value;
    struct Node *right;
    struct Node *left;
} Node;

typedef Node *Tree;

/* 1 */
void insert(Tree *root, int value);

/* 2 */
void print_pre_order(Tree root);

/* 3 */
void print_in_order(Tree root);

/* 4 */
void print_post_order(Tree root);

/* 5 */
void print_reverse_order(Tree root);

/* 6 */
int even_amount(Tree root);

/* 13 */
int exists(Tree root, int value);

#endif