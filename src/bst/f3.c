#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int main(void *args) {
    Tree tree = NULL;
    insert(&tree, 23);
    insert(&tree, 80);
    insert(&tree, 21);
    insert(&tree, 24);
    insert(&tree, 214);
    insert(&tree, 14);
    insert(&tree, 11);

    print_in_order(tree);
    printf("\n");
    return 0;
}
