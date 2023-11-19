#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

int main (void *args) {
    int option, value;
    Tree tree = NULL;
    while (1) {
        scanf("%d", &option);
        switch (option) {
            case 1:
                scanf("%d", &value);
                tree_insert(&tree, value);
                break;
            case 2:
                tree_print_pre_order(tree);
                break;
            case 3:
                tree_print_in_order(tree);
                break;
            case 4:
                tree_print_post_order(tree);
                break;
            case 5:
                tree_print_reverse_order(tree);
                break;
            case 6:
                printf("%d\n", tree_even_amount(tree));
                break;
            case 7:
                scanf("%d", &value);
                printf("%d\n", tree_predecessor(tree, value));
                break;
            case 8:
                scanf("%d", &value);
                printf("%d\n", tree_parent(tree, value));
                break;
            case 9:
                scanf("%d", &value);
                tree_remove(&tree, value);
                break;
            case 10:
                printf("%d\n", tree_even_sum(tree));
                break;
            case 11:
                scanf("%d", &value);
                tree_prune(&tree, value);
                break;
            case 12:
                tree_pow_sheets(tree);
                break;
            case 13:
                scanf("%d", &value);
                printf("%d\n", tree_exists(tree, value));
                break;
            case 14:
                scanf("%d", &value);
                tree_print_children_in_order(tree, value);
                break;
            case 99:
                exit(0);
            default:
                break;
        }
    }

    return 0;
}