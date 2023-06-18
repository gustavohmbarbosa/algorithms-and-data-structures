#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "linked_list.h"
#include "linked_list_test.h"

#define QTD_OPTIONS 17
#define TEXT_DN "Digite o valor: \n"
#define TEXT_DP "Digite a posição: \n"
#define TEXT_LS "LISTA ENCADEADA"

typedef void Action(LinkedList *list);

void header_plus(LinkedList *list, char title[], int clear) {
    if (clear) {
        system("clear");
    }

    printf("===============================\n");
    printf("%s\n", &title[0]);
    printf("===============================\n");
    linked_list_show(list);
}

void header(LinkedList *list, char text[]) {
    header_plus(list, text, 1);
}

void handle_view(int code, LinkedList *list) {
    if (code == 0) {
        system("clear");
        printf("Não foi possível realizar a operação.\n");
        header_plus(list, TEXT_LS, 0);
        return;
    }
    
    header(list, TEXT_LS);
}

typedef struct Option
{
    int code;
    char description[60];
    Action *action;
} Option;

typedef Option Options[];

void choice_option(Options *options, LinkedList *list) {
    printf("AÇÕES\n");
    for (int i = 0; i < QTD_OPTIONS; i++) {
        printf("%s\n", (*options)[i].description);
    }

    int choice;
    int was_found = 0;
    while (!was_found) {
        choice = get_integer_from_keyboard("\nEscolha a ação a ser realizada: \n");
        for (int i = 0; i < QTD_OPTIONS; i++) {
            if ((*options)[i].code == choice) {
                system("clear");
                was_found = 1;
                ((*options)[i].action)(list);
            }
        }
    }

    choice_option(options, list);
}

void view_linked_list_add_at_begin(LinkedList *list) {
    header(list, "INSERIR NO INICIO");
    linked_list_add_at_begin(list, get_integer_from_keyboard(TEXT_DN));
    header(list, TEXT_LS);
}

void view_linked_list_add(LinkedList *list) {
    header(list, "INSERIR NO FIM");
    linked_list_add(list, get_integer_from_keyboard(TEXT_DN));
    header(list, TEXT_LS);
}

void view_linked_list_add_at(LinkedList *list) {
    header(list, "INSERIR NUMA POSIÇÃO ESPECÍFICA");
    int value = get_integer_from_keyboard(TEXT_DN);
    int index = get_integer_from_keyboard(TEXT_DP);
    handle_view(linked_list_add_at(list, value, index), list);
}

void view_linked_list_insert_sorted(LinkedList *list) {
    linked_list_bubble_sort(list);
    header(list, "INSERIR VALOR MANTENDO A ORDEM");
    linked_list_insert_sorted(list, get_integer_from_keyboard(TEXT_DN));
    header(list, TEXT_LS);
}

void view_linked_list_show_reverse(LinkedList *list) {
    printf("Lista reversa: ");
    linked_list_show_reverse(list);
    header_plus(list, TEXT_LS, 0);
}

void view_linked_list_remove_last_one(LinkedList *list) {
    handle_view(linked_list_remove_last_one(list), list);
}

void view_linked_list_remove_first_one(LinkedList *list) {
    handle_view(linked_list_remove_first_one(list), list);
}

void view_linked_list_remove_at(LinkedList *list) {
    header(list, "REMOVER ITEM DE UMA POSIÇÃO ESPECÍFICA");
    handle_view(linked_list_remove_at(list, get_integer_from_keyboard(TEXT_DP)), list);
}

void view_linked_list_remove(LinkedList *list) {
    header(list, "REMOVER UM VALOR ESPECÍFICO");
    handle_view(linked_list_remove(list, get_integer_from_keyboard(TEXT_DN)), list);
}

void view_linked_list_search(LinkedList *list) {
    header(list, "BUSCAR UM VALOR ESPECÍFICO");
    int value = get_integer_from_keyboard(TEXT_DN);
    int result = linked_list_search(list, value);
    system("clear");

    if (result == -1) {
        printf("%d não existe na lista.\n", value);
    } else {
        printf("%d encontrado na posição %d.\n", value, result);
    }

    header_plus(list, TEXT_LS, 0);
}

void view_linked_list_sum(LinkedList *list) {
    printf("Soma dos valores da lista: %d\n", linked_list_sum(list));
    header_plus(list, TEXT_LS, 0);
}

void view_linked_list_size(LinkedList *list) {
    printf("Quantidade de valores da lista: %d\n", linked_list_size(list));
    header_plus(list, TEXT_LS, 0);
}

void view_linked_list_squared(LinkedList *list) {
    linked_list_squared(list);
    header_plus(list, TEXT_LS, 0);
}

void view_linked_list_prime_amount(LinkedList *list) {
    printf("Quantidade de números primos da lista: %d\n", linked_list_prime_amount(list));
    header_plus(list, TEXT_LS, 0);
}

void view_linked_list_bubble_sort(LinkedList *list) {
    linked_list_bubble_sort(list);
    header_plus(list, TEXT_LS, 0);
}

void exit_list(LinkedList *list) {
    system("clear");
    printf("Lista final: \n");
    linked_list_show(list);
    exit(0);
}

void main() {
    Options options = {
        { code: 1, description: "1 - Inserir no inicio", action: view_linked_list_add_at_begin },
        { code: 2, description: "2 - Inserir no fim", action: view_linked_list_add },
        { code: 3, description: "3 - Inserir numa posição específica", action: view_linked_list_add_at },
        { code: 4, description: "4 - Inserir valor mantendo a ordenação ", action: view_linked_list_insert_sorted }, 
        { code: 6, description: "6 - Mostrar lista reversa", action: view_linked_list_show_reverse }, 
        { code: 7, description: "7 - Remover item do fim da lista", action: view_linked_list_remove_last_one },
        { code: 8, description: "8 - Remover item do inicio da lista", action: view_linked_list_remove_first_one },
        { code: 9, description: "9 - Remover item de uma posição específica", action: view_linked_list_remove_at },
        { code: 10, description: "10 - Remover item um valor específico", action: view_linked_list_remove },
        { code: 11, description: "11 - Buscar um valor específico", action: view_linked_list_search },
        { code: 12, description: "12 - Somar todos os valores da lista", action: view_linked_list_sum },
        { code: 13, description: "13 - Exibir quantidade de valores da lista", action: view_linked_list_size },
        { code: 14, description: "14 - Elevar ao quadrado todos os valores da lista", action: view_linked_list_squared },
        { code: 15, description: "15 - Contar a quantidade de números primos da lista", action: view_linked_list_prime_amount },
        { code: 16, description: "16 - Ordenar a lista", action: view_linked_list_bubble_sort },
        { code: 42, description: "42 - Rodar testes e sair", action: run_linked_list_test },
        { code: 99, description: "99 - Sair", action: exit_list },
    };

    LinkedList main_list = NULL;
    header(&main_list, TEXT_LS);
    choice_option(&options, &main_list);
}
