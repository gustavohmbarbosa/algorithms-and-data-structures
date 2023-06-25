#include <stdio.h>
#include "stack.h"

#define STR_MAX 1000
#define TXT_BAD "Chaves mal balanceadas\n"
#define TXT_GOOD "Chaves bem balanceadas\n"

/*
Escreva um programa que recebe um string do teclado e determina se os parênteses, 
colchetes e chaves estão bem balanceados. 
Ex: 9 * { 10 + [2 / 3] + [ (-2) + (6 * 9 )] } / {-11}
*/
void main() {
    char str[STR_MAX];
    fgets(str, STR_MAX, stdin);

    Stack stack = create_stack();
    int i = 0;
    while (str[i] != '\n') {
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
