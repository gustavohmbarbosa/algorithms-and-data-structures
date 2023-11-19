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

void tree_cut_sheet(Tree *sheet) {
    free(*sheet);
    *sheet = NULL;
}

void tree_purge(Tree *root) {
    if (*root == NULL) {
        return;
    }

    tree_purge(&(*root)->right);
    tree_purge(&(*root)->left);
    tree_cut_sheet(root);
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
        tree_cut_sheet(root);
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
    tree_cut_sheet(inorder_successor);
}

int tree_even_sum(Tree root) {
    if (root == NULL) {
        return 0;
    }
    int value = (root->value % 2) == 0 ? root->value : 0;

    return value + tree_even_sum(root->left) + tree_even_sum(root->right);
}

Tree* tree_find(Tree *root, int value) {
    Tree *result = root;
    while (*result != NULL && (*result)->value != value) {
        if (value > (*result)->value) {
            result = &(*result)->right;
            continue;
        }

        if (value < (*result)->value) {
            result = &(*result)->left;
            continue;
        }
    }

    return result;
}

void tree_prune(Tree *root, int value) {
    tree_purge(tree_find(root, value));
}

void tree_pow_sheets(Tree root) {
    if (root == NULL) {
        return;
    }

    root->value = root->value * 2;
    tree_pow_sheets(root->left);
    tree_pow_sheets(root->right);
}

void tree_print_children_in_order(Tree root, int parent) {
    Tree *the_one = tree_find(&root, parent);
    _print_in_order((*the_one)->left);
    _print_in_order((*the_one)->right);
    printf("\n");
}

int tree_height(Tree root) {
    if (root == NULL) {
        return 0;
    }

    int result = 1;
    int right_amount = 0;
    if (root->right != NULL) {
        right_amount = tree_height(root->right);
    }

    int left_amount = 0;
    if (root->left != NULL) {
        left_amount = tree_height(root->left);
    }

    result += right_amount > left_amount ? right_amount : left_amount;

    return result;
}
