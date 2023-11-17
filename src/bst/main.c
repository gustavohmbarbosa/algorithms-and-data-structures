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
                insert(&tree, value);
                break;
            case 2:
                print_pre_order(tree);
                break;
            case 3:
                print_in_order(tree);
                break;
            case 4:
                print_post_order(tree);
                break;
            case 5:
                print_reverse_order(tree);
                break;
            case 6:
                even_amount(tree);
                printf("\n");
                break;
            case 13:
                scanf("%d", &value);
                printf("%d\n", exists(tree, value));
                break;
            case 99:
                exit(0);
            default:
                break;
        }
    }

    return 0;
}