#include <stdio.h>
#include "stack.h"

#define STR_MAX 1000
#define TXT_BAD "Chaves mal balanceadas\n"
#define TXT_GOOD "Chaves bem balanceadas\n"

/*
Escreva um programa que recebe um string do teclado e determina se os parênteses, 
colchetes e chaves estão bem balanceados. 
Ex: 9 * { 10 + [2 / 3] + [ (-2) + (6 * 9 )] } / {-11}

FIXME: tratar melhor os caracteres lidos, pois casos como este: "/ {}}" tem uma falha lógica,
pois acaba chegando no "/0" antes mesmo de finalizar toda a leitura.
*/
void main() {
    char str[STR_MAX];
    scanf("%s", str);

    Stack stack = create_stack();
    int i = 0;
    while (str[i] != 0) {
        switch (str[i]) {
            case '{':
                push(&stack, (int) '{');
                break;
            case '}':
                if (pop(&stack) != (int) '{') {
                    printf("%s", TXT_BAD);
                    return;
                }
                break;

            case '[':
                push(&stack, (int) '[');
                break;
            case ']':
                if (pop(&stack) != (int) '[') {
                    printf("%s", TXT_BAD);
                    return;
                }
                break;

            case '(':  
                push(&stack, (int) '(');
                break;
            case ')':  
                if (pop(&stack) != (int) '(') {
                    printf("%s", TXT_BAD);
                    return;
                }
        }

        i++;
    }

    if (!is_empty(&stack)) {
        printf("%s", TXT_BAD);
        return;
    }

    printf(TXT_GOOD);
}
