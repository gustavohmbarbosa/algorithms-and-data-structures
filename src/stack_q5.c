#include <stdio.h>
#include "stack.h"

/**
Escreva um programa que recebe um string e determina se o string digitado é um palíndromo. 
Ex: anilina, ovo, osso, radar, sopapos, socos.

Obs: Acentos e espaços em branco devem ser desconsiderados. 
Ex: A mae te ama; luz azul; o galo ama o lago.
*/

void main() {
    char str[1000];
    fgets(str, 1000, stdin);

    Stack stack = create_stack();
    int i = 0;
    while (str[i] != '\n') {
        if (str[i] != ' ') {
            push(&stack, (int) str[i]);
        }
        i++;
    }

    i = 0;
    while (stack.size) {
        if (str[i] != ' ') {
            if (str[i] != pop(&stack)) {
                printf("Não é um palíndromo\n");
                return;
            }
        }

        i++;
    }
    
    printf("É um palíndromo\n");
}
