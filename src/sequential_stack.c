#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "sequential_list.h"

typedef List *StackList;

Stack create_stack() {
    StackList stack_list = (StackList) malloc(sizeof(List));
    stack_list->length = 0;

    Stack stack = {
        top: NULL,
        size: 0,
        data: stack_list
    };

    return stack;
}

int push(Stack *stack, int value) {
    StackList stack_list = (List *) stack->data;
    int success = list_insert(stack_list, value);

    if (success) {
        stack->size++;
        return 1;
    }

    return 0;
}

void print_stack(Stack *stack) {
    if (is_empty(stack)) {
        printf("[]\n");
        return;
    }

    StackList stack_list = (List *) stack->data;
    for (int i = stack_list->length - 1; i >= 0; i--) {
        printf("[%d]\n", stack_list->items[i]);
    }
}

int is_empty(Stack *stack) {
    return stack->size <= 0;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        return 0;
    }

    StackList stack_list = (StackList) stack->data;
    int last_item = stack_list->items[stack_list->length -1];
    list_remove_last(stack_list);
    stack->size--;

    return last_item;
}

int top(Stack *stack) {
    if (is_empty(stack)) {
        return 0;
    }

    StackList stack_list = (StackList) stack->data;

    return stack_list->items[stack_list->length - 1];
}

// void main() {
void test_main() {
    Stack stack = create_stack();

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    print_stack(&stack);
    printf("\n");

    printf("POP %d\n", pop(&stack));
    printf("POP %d\n", pop(&stack));
    print_stack(&stack);
    printf("TOP %d\n", top(&stack));

    printf("\n");

    printf("POP %d\n", pop(&stack));
    printf("POP %d\n", pop(&stack));
    printf("TOP %d\n", top(&stack));
    print_stack(&stack);
    
    printf("\n");

    printf("POP %d\n", pop(&stack));
    printf("POP %d\n", pop(&stack));
    print_stack(&stack);
    printf("TOP %d\n", top(&stack));
}
