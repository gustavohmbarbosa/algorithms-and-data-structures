#include <stdio.h>
#include "stack.h"

/**
Escreva um programa COMPUTACIONALMENTE EFICIENTE que acumula n valores da 
sequência de Fibonacci em uma pilha. Observação: Não utilize função recursiva e evite cálculos 
repetitivos.

OBS: Como está sendo utilizado uma pilha de números inteiros(int), n está entre [0, 46]
*/
void main() {
    int n;
    scanf("%d", &n);

    int predecessor = 0;
    Stack stack = create_stack();

    if (n > 0) {
        push(&stack, 1);
    }

    int current;
    while(stack.size < n) {
        current = predecessor + top(&stack);
        predecessor = top(&stack);
        push(&stack, current);
    }

    print_stack(&stack);
}
