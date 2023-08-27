#ifndef SEQUENTIAL_LIST_H
#define SEQUENTIAL_LIST_H

#define MAX 10

typedef struct List
{
    int items[MAX];
    int length;
} List;

List list();

void list_print(List *list);

int list_equals(List *list1, List *list2);

// OP 1
int list_insert_first(List *list, int value);

// OP 2
int list_insert(List *list, int value);

// OP 3
int list_insert_at(List *list, int value, unsigned int index);

// OP 4
int list_insert_sorted(List *list, int value);

// OP 5
void list_show(List *list);

// OP 6
void list_show_reverse(List *list);

// OP 9
int list_remove_at(List *list, unsigned int index);

// OP 7
int list_remove_first(List *list);

// OP 8
int list_remove_last(List *list);

// OP 10
int list_remove(List *list, int value);

// OP 11
int list_linear_search(List *list, int value);

// OP 12
int list_sum(List *list);

// OP 14
void list_squared(List *list);

// OP 15
int list_prime_amount(List *list);

void list_bubble_sort(List *list);

void list_selection_sort(List *list);

void list_insertion_sort(List *list);

#endif