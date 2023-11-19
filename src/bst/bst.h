#ifndef BST_H
#define BST_H

typedef struct Node {
    int value;
    struct Node *right;
    struct Node *left;
} Node;

typedef Node *Tree;

/* 1 */
void tree_insert(Tree *root, int value);

/* 2 */
void tree_print_pre_order(Tree root);

/* 3 */
void tree_print_in_order(Tree root);

/* 4 */
void tree_print_post_order(Tree root);

/* 5 */
void tree_print_reverse_order(Tree root);

/* 6 */
int tree_even_amount(Tree root);

/* 7 */
int tree_predecessor(Tree root, int value);

/* 8 */
int tree_parent(Tree root, int value);

/* 9 ((void *)0) */
void tree_remove(Tree *root, int value);

/* 10 */
int tree_even_sum(Tree root);

/* 11 */
void tree_prune(Tree *root, int value);

/* 12 */
void tree_pow_sheets(Tree root);

/* 13 */
int tree_exists(Tree root, int value);

#endif