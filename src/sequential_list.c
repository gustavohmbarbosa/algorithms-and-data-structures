#include <stdio.h>
#include "utils.h"
#include "sequential_list.h"

List list() {
    List list;
    list.length = 0;    
    return list;
}

void list_print(List *list) {
    printf("[\n");
    for (int i = 0; i < list->length; i++) {
        printf("   %d: %d\n", i, list->items[i]);
    }
    printf("]\n");
}

int list_equals(List *list1, List *list2) {
    if (list1->length != list2->length) {
        return 0;
    }

    for (int i = 0; i < list1->length; i++) {
        if (list1->items[i] != list2->items[i]) {
            return 0;
        }
    }

    return 1;
}

int can_insert(List *list, unsigned int index) {
    return list->length < MAX && index <= list->length;
}

int list_insert_first(List *list, int value) {
    return list_insert_at(list, value, 0);
}

int list_insert(List *list, int value) {
    return list_insert_at(list, value, list->length);
}

int list_insert_at(List *list, int value, unsigned int index) {
    if (!can_insert(list, index)) {
        return 0;
    }

    for (int i = list->length; i > index; i--) {
        list->items[i] = list->items[i - 1]; 
    }
    list->items[index] = value;
    list->length++;
    
    return 1;
}

int list_insert_sorted(List *list, int value) {
    if (!can_insert(list, 0)) {
        return 0;
    }

    if (!list->length) {
        return list_insert_at(list, value, 0);
    }

    for (int i = 0; i < list->length; i++) {
        if (value <= list->items[i]) {
            return list_insert_at(list, value, i); 
        }
    }

    return list_insert_at(list, value, list->length); 
}

void list_show(List *list) {
    if (!list->length) {
        printf("[]");
    }

    for (int i = 0; i < list->length; i++) {
        printf("[%d]", list->items[i]);
    }

    printf("\n");
}

void list_show_reverse(List *list) {
    for (int i = list->length - 1; i >= 0; i--) {
        printf("[%d]", list->items[i]);
    }

    printf("\n");
}

int can_remove(List *list, unsigned int index) {
    return list->length > 1 && list->length > index && index >= 0;
}

int list_remove_at(List *list, unsigned int index) {
    if (!can_remove(list, index)) {
        return 0;
    }

    list->length--;
    for (int i = index; i < list->length; i++) {
        list->items[i] = list->items[i + 1]; 
    }
    
    return 1;
}

int list_remove_first(List *list) {
    return list_remove_at(list, 0);
}

int list_remove_last(List *list) {
    return list_remove_at(list, list->length - 1);
}

int list_remove(List *list, int value) {
    if (!can_remove(list, 0)) {
        return 0;
    }
    
    return list_remove_at(list, list_linear_search(list, value));
}

int list_linear_search(List *list, int value) {
    for (int i = 0; i < list->length; i++) {
        if (value == list->items[i]) {
            return i; 
        }
    }
    
    return -1;
}

int list_sum(List *list) {
    int result = 0;
    for (int i = 0; i < list->length; i++) {
        result += list->items[i];
    }

    return result;
}

void list_squared(List *list) {
    for (int i = 0; i < list->length; i++) {
        list->items[i] *= list->items[i];
    }
}

int list_prime_amount(List *list) {
    int result = 0;

    for (int i = 0; i < list->length; i++) {
        if (is_prime(list->items[i])) {
            result++;
        }
    }

    return result;
}

void list_bubble_sort(List *list) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < list->length - 1; i++) {
            if (list->items[i] > list->items[i + 1]) {
                int temp = list->items[i];
                list->items[i] = list->items[i + 1];
                list->items[i + 1] = temp; 
                swapped = 1;
            }
        }
    } while (swapped);
}
