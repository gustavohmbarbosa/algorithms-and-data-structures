#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "linked_list.h"

void linked_list_print(LinkedList list) {
    if (list == NULL) {
        printf("[]\n");
        return;
    }

    printf("[\n");
    LinkedList temp = list;
    int i = 0;
    while (temp != NULL) {        
        printf("   %d: %d\n", i, temp->value);
        temp = temp->next;
        i++;
    }
    printf("]\n");
}

int linked_list_equals(LinkedList l1, LinkedList l2) {
    if (l1 == l2) {
        return 1;
    }

    LinkedList temp1 = l1;
    LinkedList temp2 = l2;
    while (temp1 != NULL || temp2 != NULL) {
        if (
            (temp1 == NULL && temp2 != NULL) ||
            (temp2 == NULL && temp1 != NULL)
        ) {
            return 0;
        } 

        if (temp1->value != temp2->value) {
            return 0;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 1;
}

void linked_list_show(LinkedList *list) {
    if(*list == NULL) {
        printf("\n");
        return;
    }

    printf("[%d]", (*list)->value);
    linked_list_show(&(*list)->next);
}

Record *linked_list_add_at_begin(LinkedList *list, int value) {
    LinkedList new = (LinkedList) malloc(sizeof(Record));
    new->value = value;
    new->next = *list;
    *list = new;

    return new;
}

Record *linked_list_add(LinkedList *list, int value) {
    if (*list == NULL) {
        return linked_list_add_at_begin(list, value);
    }

    LinkedList new = (LinkedList) malloc(sizeof(Record));
    new->value = value;
    new->next = NULL;

    LinkedList last_record = *list;
    while (last_record->next != NULL) {
        last_record = last_record->next;
    }

    last_record->next = new;

    return new;
}

Record *linked_list_add_at(LinkedList *list, int value, int index) {
    if (index < 0) {
        return NULL;
    }

    if (index == 0) {
        return linked_list_add_at_begin(list, value);
    }

    if (*list == NULL) {
        return NULL;
    }
    
    int i = 0;
    LinkedList temp = *list;
    while (temp != NULL) {
        if ((i + 1) != index) {
            i++;
            temp = temp->next;
            continue;
        }

        LinkedList new = (LinkedList) malloc(sizeof(Record));
        new->value = value;
        new->next = temp->next;

        temp->next = new;

        return new;
    }

    return NULL;
}

void internal_show_reverse(LinkedList *list) {
    if (*list == NULL) {
        return;
    }

    internal_show_reverse(&(*list)->next);
    printf("[%d]", (*list)->value);
}

void linked_list_show_reverse(LinkedList *list) {
    internal_show_reverse(list);
    printf("\n");
}

int linked_list_remove_first_one(LinkedList *list) {
    if (*list == NULL) {
        return 0;
    }

    LinkedList first_one = *list;
    *list = (*list)->next;
    free(first_one);
    return 1;
}

int linked_list_remove_last_one(LinkedList *list) {
    if (*list == NULL) {
        return 0;
    }

    if ((*list)->next == NULL) {
        return linked_list_remove_first_one(list);
    }

    LinkedList temp = *list;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return 1;
}

int internal_remove_from_list(LinkedList *before_record) {
    LinkedList the_one_to_remove = (*before_record)->next;
    if (the_one_to_remove == NULL) { // that one is also the last one
        free(the_one_to_remove);
        (*before_record)->next = NULL;
        return 1;
    }

    (*before_record)->next = the_one_to_remove->next;
    free(the_one_to_remove);
    return 1;
}

int linked_list_remove_at(LinkedList *list, int index) {
    if (index < 0) {
        return 0;
    }

    if (index == 0) {
        return linked_list_remove_first_one(list);
    }

    if (*list == NULL) {
        return 0;
    }

    int i = 0;
    LinkedList temp = *list;
    while (temp->next != NULL) {
        if ((i + 1) != index) {
            i++;
            temp = temp->next;
            continue;
        }

        return internal_remove_from_list(&temp);
    }

    return 0;
}

int linked_list_remove(LinkedList *list, int value){
    if (*list == NULL) {
        return 0;
    }

    if ((*list)->value == value) {
        return linked_list_remove_first_one(list);
    }

    int i = 0;
    LinkedList temp = *list;
    while (temp != NULL) {
        if (temp->next->value != value) {
            i++;
            temp = temp->next;
            continue;
        }
       
        return internal_remove_from_list(&temp);
    }
    
    return 0;
}

int linked_list_search(LinkedList *list, int value) {
    int i = 0;
    LinkedList temp = *list;
    while (temp != NULL) {
        if (temp->value == value) {
            return i;
        }

        i++;
        temp = temp->next;
    }
    
    return -1;
}

int linked_list_sum(LinkedList *list) {
    int result = 0;

    LinkedList temp = *list;
    while (temp != NULL) {
        result += temp->value;
        temp = temp->next;
    }
    
    return result;
}

int linked_list_size(LinkedList *list) {
    if (*list == NULL) {
        return 0;
    }
    
    return 1 + linked_list_size(&(*list)->next);
}

void linked_list_squared(LinkedList *list) {
    if (*list == NULL) {
        return;
    }
    
    (*list)->value *= (*list)->value;
    return linked_list_squared(&(*list)->next);
}

int linked_list_prime_amount(LinkedList *list) {
    if (*list == NULL) {
        return 0;
    }
    
    return is_prime((*list)->value) + linked_list_prime_amount(&(*list)->next);
}

void linked_list_bubble_sort(LinkedList *list) {
    int swapped;
    do {
        swapped = 0;
        LinkedList temp = *list;

        while (temp->next != NULL) {
            if (temp->value > temp->next->value) {
                int value_to_swapped = temp->value;
                temp->value = temp->next->value;
                temp->next->value = value_to_swapped;
                swapped = 1;
            }

            temp = temp->next;
        }
    } while (swapped);
}

Record *linked_list_insert_sorted(LinkedList *list, int value) {
    if (*list == NULL || (*list)->value > value) {
        return linked_list_add_at_begin(list, value);
    }

    LinkedList temp = *list; 
    while (temp->next != NULL) {
        if (temp->next->value < value) {
            temp = temp->next;
            continue;
        }

        LinkedList new = (LinkedList) malloc(sizeof(Record));
        new->value = value;
        new->next = temp->next;
        temp->next = new;

        return new;
    }
    
    return linked_list_add(list, value);
}
