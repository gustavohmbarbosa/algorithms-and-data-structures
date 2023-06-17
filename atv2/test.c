#include <stdlib.h>
#include <stdio.h>
#include "test.h"
#include "linked_list.h"

void test_linked_list_equals() {
    { // com duas iguais nulas
        LinkedList l1 = NULL;
        LinkedList l2 = NULL;

        if (!linked_list_equals(l1, l2)) {
            printf("[FAIL-1] test_linked_list_equals\n");
            printf("expected: 1\n");

            printf("received: 0\n");
            exit(TEST_ERROR);
        }
    }
    
    { // com duas iguais não nulas
        LinkedList l1 = NULL;
        linked_list_add_at_begin(&l1, 20);
        linked_list_add_at_begin(&l1, 10);

        LinkedList l2 = NULL;
        linked_list_add_at_begin(&l2, 20);
        linked_list_add_at_begin(&l2, 10);

        if (!linked_list_equals(l1, l2)) {
            printf("[FAIL-2] test_linked_list_equals\n");
            printf("expected: 1\n");

            printf("received: 0\n");
            exit(TEST_ERROR);
        }
    }

    { // com duas não iguais com tamanhos diferentes
        LinkedList l1 = NULL;
        linked_list_add_at_begin(&l1, 20);
        linked_list_add_at_begin(&l1, 10);

        LinkedList l2 = NULL;
        linked_list_add_at_begin(&l2, 10);

        if (linked_list_equals(l1, l2)) {
            printf("[FAIL-3] test_linked_list_equals\n");
            printf("expected: 0\n");

            printf("received: 1\n");
            exit(TEST_ERROR);
        }
    }

    { // com duas não iguais com mesmo tamanho
        LinkedList l1 = NULL;
        linked_list_add_at_begin(&l1, 20);
        linked_list_add_at_begin(&l1, 10);

        LinkedList l2 = NULL;
        linked_list_add_at_begin(&l1, 50);
        linked_list_add_at_begin(&l2, 10);

        if (linked_list_equals(l1, l2)) {
            printf("[FAIL-4] test_linked_list_equals\n");
            printf("expected: 0\n");

            printf("received: 1\n");
            exit(TEST_ERROR);
        }
    }

    { // com duas não iguais, uma nula e outra não
        LinkedList l1 = NULL;
        linked_list_add_at_begin(&l1, 20);
        linked_list_add_at_begin(&l1, 10);

        LinkedList l2 = NULL;

        if (linked_list_equals(l1, l2)) {
            printf("[FAIL-5] test_linked_list_equals\n");
            printf("expected: 0\n");

            printf("received: 1\n");
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_equals\n");
}

void test_linked_list_add_at_begin() {
    Record r1 = {
        value: 20,
        next: NULL
    };
    Record r2 = {
        value: 10,
        next: &r1
    };
    LinkedList expectedList = &r2;

    LinkedList result = NULL;
    linked_list_add_at_begin(&result, 20);
    linked_list_add_at_begin(&result, 10);

    if (!linked_list_equals(expectedList, result)) {
        printf("[FAIL-1] test_linked_list_add_at_begin\n");
        printf("expected: ");
        linked_list_print(expectedList);

        printf("received: ");
        linked_list_print(result);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_linked_list_add_at_begin\n");
}

void test_linked_list_add() {
    Record r1 = {
        value: 20,
        next: NULL
    };
    Record r2 = {
        value: 10,
        next: &r1
    };
    LinkedList expectedList = &r2;

    LinkedList result = NULL;
    linked_list_add(&result, 10);
    linked_list_add(&result, 20);

    if (!linked_list_equals(expectedList, result)) {
        printf("[FAIL-1] test_linked_list_add\n");
        printf("expected: ");
        linked_list_print(expectedList);

        printf("received: ");
        linked_list_print(result);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_linked_list_add\n");
}

void test_linked_list_add_at() {
    Record r4 = {
        value: 40,
        next: NULL
    };
    Record r3 = {
        value: 30,
        next: &r4
    };
    Record r2 = {
        value: 20,
        next: &r3
    };
    Record r1 = {
        value: 10,
        next: &r2
    };
    LinkedList expectedList = &r1;

    LinkedList result = NULL;
    linked_list_add_at(&result, 99, 99); // do nothing
    linked_list_add_at(&result, 10, 0); // [10]
    linked_list_add_at(&result, 99, 99); // do nothing
    linked_list_add_at(&result, 30, 1); // [10, 30]
    linked_list_add_at(&result, 20, 1); // [10, 20, 30]
    linked_list_add_at(&result, 40, 3); // [10, 20, 30, 40]
    linked_list_add_at(&result, 99, 5); // do nothing

    if (!linked_list_equals(expectedList, result)) {
        printf("[FAIL-1] test_linked_list_add_at\n");
        printf("expected: ");
        linked_list_print(expectedList);

        printf("received: ");
        linked_list_print(result);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_linked_list_add_at\n");
}

void test_linked_list_show_reverse() {
    LinkedList result = NULL;
    linked_list_add(&result, 10);
    linked_list_add(&result, 20);
    linked_list_add(&result, 30);

    linked_list_show_reverse(result);
    printf("[SUCCESS] test_linked_list_show_reverse\n");
}

void test_linked_list_remove_first_one() {
    {
        LinkedList expectedList = NULL;
        linked_list_add(&expectedList, 20);
        linked_list_add(&expectedList, 30);

        LinkedList result = NULL;
        linked_list_remove_first_one(&result);
        linked_list_add(&result, 10);
        linked_list_add(&result, 20);
        linked_list_add(&result, 30);
        linked_list_remove_first_one(&result);

        if (!linked_list_equals(expectedList, result)) {
            printf("[FAIL-1] test_linked_list_remove_first_one\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList expectedList = NULL;
        
        LinkedList result = NULL;
        linked_list_add(&result, 10);
        linked_list_add(&result, 30);
        linked_list_remove_first_one(&result);
        linked_list_remove_first_one(&result);
        linked_list_remove_first_one(&result);

        if (!linked_list_equals(expectedList, result)) {
            printf("[FAIL-2] test_linked_list_remove_first_one\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(result);
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_remove_first_one\n");
}

void test_linked_list_remove_last_one() {
    {
        LinkedList expectedList = NULL;
        linked_list_add(&expectedList, 20);

        LinkedList result = NULL;
        linked_list_remove_last_one(&result);
        linked_list_add(&result, 10);
        linked_list_remove_last_one(&result);
        linked_list_add(&result, 20);
        linked_list_add(&result, 30);
        linked_list_remove_last_one(&result);

        if (!linked_list_equals(expectedList, result)) {
            printf("[FAIL-1] test_linked_list_remove_last_one\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList expectedList = NULL;
        
        LinkedList result = NULL;
        linked_list_add(&result, 10);
        linked_list_add(&result, 30);
        linked_list_remove_last_one(&result);
        linked_list_remove_last_one(&result);
        linked_list_remove_last_one(&result);

        if (!linked_list_equals(expectedList, result)) {
            printf("[FAIL-2] test_linked_list_remove_last_one\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(result);
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_remove_last_one\n");
}

void test_linked_list_remove_at() {
    {
        LinkedList expectedList = NULL;
        linked_list_add(&expectedList, 20);

        LinkedList result = NULL;
        linked_list_remove_at(&result, 1); // []
        linked_list_add(&result, 10); // [10]
        linked_list_remove_at(&result, 0); // []
        linked_list_add(&result, 20); // [20]
        linked_list_add(&result, 30); // [20, 30]
        linked_list_add(&result, 40); // [20, 30, 40]
        linked_list_add(&result, 50); // [20, 30, 40, 50]
        linked_list_remove_at(&result, 1); // [20, 40, 50]
        linked_list_remove_at(&result, 2); // [20, 40]
        linked_list_remove_at(&result, 1); // [20]

        if (!linked_list_equals(expectedList, result)) {
            printf("[FAIL-1] test_linked_list_remove_at\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList expectedList = NULL;
        
        LinkedList result = NULL;
        linked_list_add(&result, 10);
        linked_list_add(&result, 30);
        linked_list_remove_at(&result, 0);
        linked_list_remove_at(&result, 0);
        linked_list_remove_at(&result, 0);

        if (!linked_list_equals(expectedList, result)) {
            printf("[FAIL-2] test_linked_list_remove_at\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(result);
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_remove_at\n");
}

void test_linked_list_remove() {
    {
        LinkedList expectedList = NULL;
        linked_list_add(&expectedList, 20);

        LinkedList result = NULL;
        linked_list_remove(&result, 99); // []
        linked_list_add(&result, 10); // [10]
        linked_list_remove(&result, 10); // []
        linked_list_add(&result, 20); // [20]
        linked_list_add(&result, 30); // [20, 30]
        linked_list_add(&result, 40); // [20, 30, 40]
        linked_list_add(&result, 50); // [20, 30, 40, 50]
        linked_list_remove(&result, 30); // [20, 40, 50]
        linked_list_remove(&result, 50); // [20, 40]
        linked_list_remove(&result, 40); // [20]

        if (!linked_list_equals(expectedList, result)) {
            printf("[FAIL-1] test_linked_list_remove\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList expectedList = NULL;
        
        LinkedList result = NULL;
        linked_list_add(&result, 10);
        linked_list_add(&result, 30);
        linked_list_remove(&result, 10);
        linked_list_remove(&result, 30);
        linked_list_remove(&result, 99);

        if (!linked_list_equals(expectedList, result)) {
            printf("[FAIL-2] test_linked_list_remove\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(result);
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_remove\n");
}

void test_linked_list_search() {
    {
        LinkedList list = NULL;
        int expectedResult = -1;
        int result = linked_list_search(&list, 42);

        if (result != expectedResult) {
            printf("[FAIL-1] test_linked_list_search\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList list = NULL;
        linked_list_add(&list, 10);
        linked_list_add(&list, 20);
        linked_list_add(&list, 30);

        int expectedResult = 2;
        int result = linked_list_search(&list, 30);

        if (result != expectedResult) {
            printf("[FAIL-2] test_linked_list_search\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList list = NULL;
        linked_list_add(&list, 10);
        linked_list_add(&list, 20);
        linked_list_add(&list, 30);

        int expectedResult = 0;
        int result = linked_list_search(&list, 10);

        if (result != expectedResult) {
            printf("[FAIL-3] test_linked_list_search\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList list = NULL;
        linked_list_add(&list, 10);
        linked_list_add(&list, 20);
        linked_list_add(&list, 30);

        int expectedResult = 1;
        int result = linked_list_search(&list, 20);

        if (result != expectedResult) {
            printf("[FAIL-4] test_linked_list_search\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList list = NULL;
        linked_list_add(&list, 10);
        linked_list_add(&list, 20);
        linked_list_add(&list, 30);

        int expectedResult = -1;
        int result = linked_list_search(&list, 42);

        if (result != expectedResult) {
            printf("[FAIL-5] test_linked_list_search\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_search\n");
}

void test_linked_list_sum() {
    {
        LinkedList list = NULL;
        int expectedResult = 0;
        int result = linked_list_sum(&list);

        if (result != expectedResult) {
            printf("[FAIL-1] test_linked_list_sum\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList list = NULL;
        linked_list_add(&list, 10);
        linked_list_add(&list, -20);
        linked_list_add(&list, 30);
        linked_list_add(&list, -62);

        int expectedResult = -42;
        int result = linked_list_sum(&list);

        if (result != expectedResult) {
            printf("[FAIL-2] test_linked_list_sum\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_sum\n");
}

void test_linked_list_size() {
    {
        LinkedList list = NULL;
        int expectedResult = 0;
        int result = linked_list_size(&list);

        if (result != expectedResult) {
            printf("[FAIL-1] test_linked_list_size\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList list = NULL;
        linked_list_add(&list, 10);
        linked_list_add(&list, -20);
        linked_list_add(&list, 30);
        linked_list_add(&list, -62);

        int expectedResult = 4;
        int result = linked_list_size(&list);

        if (result != expectedResult) {
            printf("[FAIL-2] test_linked_list_size\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_size\n");
}

void test_linked_list_squared() {
    {
        LinkedList list = NULL;
        LinkedList expectedList = NULL;
        linked_list_squared(&list);

        if (!linked_list_equals(expectedList, list)) {
            printf("[FAIL-1] test_linked_list_squared\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(list);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList list = NULL;
        linked_list_add(&list, 2);
        linked_list_add(&list, 0);
        linked_list_add(&list, 4);
        linked_list_add(&list, -2);

        LinkedList expectedList = NULL;
        linked_list_add(&expectedList, 4);
        linked_list_add(&expectedList, 0);
        linked_list_add(&expectedList, 16);
        linked_list_add(&expectedList, 4);

        linked_list_squared(&list);

        if (!linked_list_equals(expectedList, list)) {
            printf("[FAIL-2] test_linked_list_squared\n");
            printf("expected: ");
            linked_list_print(expectedList);

            printf("received: ");
            linked_list_print(list);
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_squared\n");
}

void test_linked_list_prime_amount() {
    {
        LinkedList list = NULL;
        int expectedResult = 0;
        int result = linked_list_prime_amount(&list);

        if (result != expectedResult) {
            printf("[FAIL-1] test_linked_list_prime_amount\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    {
        LinkedList list = NULL;
        linked_list_add(&list, 0);
        linked_list_add(&list, 1);
        linked_list_add(&list, 2);
        linked_list_add(&list, 3);
        linked_list_add(&list, 200);
        linked_list_add(&list, 103);
        linked_list_add(&list, 50);
        linked_list_add(&list, 257);

        int expectedResult = 4;
        int result = linked_list_prime_amount(&list);

        if (result != expectedResult) {
            printf("[FAIL-2] test_linked_list_prime_amount\n");
            printf("expected: %d\n", expectedResult);

            printf("received: %d\n", result);
            exit(TEST_ERROR);
        }
    }

    printf("[SUCCESS] test_linked_list_prime_amount\n");
}

void test_linked_list_bubble_sort() {
    LinkedList expectedList = NULL;
    linked_list_add(&expectedList, 0);
    linked_list_add(&expectedList, 1);
    linked_list_add(&expectedList, 2);
    linked_list_add(&expectedList, 3);
    linked_list_add(&expectedList, 10);
    linked_list_add(&expectedList, 50);
    linked_list_add(&expectedList, 103);
    linked_list_add(&expectedList, 200);
    linked_list_add(&expectedList, 257);

    LinkedList list = NULL;
    linked_list_add(&list, 2);
    linked_list_add(&list, 3);
    linked_list_add(&list, 1);
    linked_list_add(&list, 200);
    linked_list_add(&list, 103);
    linked_list_add(&list, 50);
    linked_list_add(&list, 257);
    linked_list_add(&list, 10);
    linked_list_add(&list, 0);
    linked_list_bubble_sort(&list);

    if(!linked_list_equals(list, expectedList)) {
        printf("[FAIL-1] test_linked_list_bubble_sort\n");
        printf("expected: ");
        linked_list_print(expectedList);

        printf("received: ");
        linked_list_print(list);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_linked_list_bubble_sort\n");
}


void run_tests() {
    test_linked_list_equals();
    test_linked_list_add_at_begin();
    test_linked_list_add();
    test_linked_list_add_at();
    // test_linked_list_show_reverse();
    test_linked_list_remove_first_one();
    test_linked_list_remove_last_one();
    test_linked_list_remove_at();
    test_linked_list_remove();
    test_linked_list_search();
    test_linked_list_sum();
    test_linked_list_size();
    test_linked_list_squared();
    test_linked_list_prime_amount();
    test_linked_list_bubble_sort();
    
    exit(0);
}
