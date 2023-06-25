#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    void *data;
    void *top;
    int size;
} Stack;

Stack create_stack();

// Retorna 1 para sucesso e 0 para erro
int push(Stack *stack, int value);

// Retorna o valor removido.
// Caso a lista esteja vazia, será retornado zero.
// Sim, zero pode ser um valor removido, então se for preciso, basta verificar
// se a lista está vazia antes de tentar remover.
int pop(Stack *stack);

// // Retorna o valor do top da pilha
// // Comportamento de retorno zero semelhante a função pop.
int top(Stack *stack);

int is_empty(Stack *stack);

void print_stack(Stack *stack);

#endif