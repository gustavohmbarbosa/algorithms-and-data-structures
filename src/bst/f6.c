#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int main(void *args) {
    Tree t1 = NULL;
    insert(&t1, 3);
    insert(&t1, 1);
    insert(&t1, 5);
    insert(&t1, 8);
    printf("%d\n", even_amount(t1));
    
    Tree t2 = NULL;
    insert(&t2, 23);
    insert(&t2, 3);
    insert(&t2, 1);
    insert(&t2, 7);
    insert(&t2, 13);
    insert(&t2, 15);
    printf("%d\n", even_amount(t2));
    
    Tree t3 = NULL;
    insert(&t3, 8);
    insert(&t3, 3);
    insert(&t3, 2);
    insert(&t3, 22);
    insert(&t3, 5);
    insert(&t3, 50);
    printf("%d\n", even_amount(t3));
    return 0;
}