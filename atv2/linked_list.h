#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Record {
    int value;
    struct Record *next;
} Record;

typedef Record *LinkedList;

void linked_list_print(LinkedList list);

int linked_list_equals(LinkedList l1, LinkedList l2);

// OP 5
void linked_list_show(LinkedList list);

// OP 1
void linked_list_add_at_begin(LinkedList *list, int value);

// OP 2
void linked_list_add(LinkedList *list, int value);

// OP 3
int linked_list_add_at(LinkedList *list, int value, unsigned int index);

// OP 6
void linked_list_show_reverse(LinkedList list);

// OP 7
int linked_list_remove_first_one(LinkedList *list);

// OP 8
int linked_list_remove_last_one(LinkedList *list);

// OP 9
int linked_list_remove_at(LinkedList *list, unsigned int index);

// OP 10
int linked_list_remove(LinkedList *list, int value);

// OP 11
int linked_list_search(LinkedList *list, int value);

// OP 12
int linked_list_sum(LinkedList *list);

// OP 13
int linked_list_size(LinkedList *list);

// OP 14
void linked_list_squared(LinkedList *list);

// OP 15
int linked_list_prime_amount(LinkedList *list);

void linked_list_bubble_sort(LinkedList *list);

// OP 4
void linked_list_insert_sorted(LinkedList *list, int value);

#endif
