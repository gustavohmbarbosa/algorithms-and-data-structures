#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "linked_list.h"

typedef LinkedList *StackList;

Stack create_stack() {
    StackList stack_list = (StackList) malloc(sizeof(StackList));
    Stack stack = { 
        top: NULL,
        size: 0,
        data: stack_list
    };
    
    return stack;
}

int push(Stack *stack, int value) {
    LinkedList *stack_list = (LinkedList*) stack->data;
    linked_list_add_at_begin(stack_list, value);
    stack->size++;
    
    return 1;
}

void print_stack(Stack *stack) {
    LinkedList *stack_list = (LinkedList*) stack->data;

    LinkedList temp = *stack_list;
    while (temp != NULL) {
        printf("[%d]\n", temp->value);
        temp = temp->next;
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
    int last_value = (*stack_list)->value;
    linked_list_remove_first_one(stack_list);
    stack->size--;

    return last_value;
}

int top(Stack *stack) {
    if (is_empty(stack)) {
        return 0;
    }

    StackList stack_list = (StackList) stack->data;

    return (*stack_list)->value;
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
