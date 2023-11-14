#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int main(void *args) {
    Tree tree = NULL;
    insert(&tree, 40);
    insert(&tree, 20);
    insert(&tree, 50);

    print_pre_order(tree);
    printf("\n");
    return 0;
}
