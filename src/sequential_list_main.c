#include <stdio.h>
#include <stdlib.h>
#include "sequential_list.h"

#define DEBUG_MODE 1
#define TEST_ERROR -42
#define QTD_OPTIONS 16
#define TEXT_DN "Digite o valor: \n"
#define TEXT_DP "Digite a posição: \n"
#define TEXT_LS "LISTA SEQUENCIAL"

void test_from_1_to_3() {
    List l1 = list();
    List l2 = {
        items: { 10, 20, 30, 40, 50 },
        length: 5
    };

    // do nothing
    list_insert_at(&l1, 20, 12);

    // teste OP3
    list_insert_at(&l1, 40, 0);

    // teste OP1
    list_insert_first(&l1, 30);
    list_insert_first(&l1, 10);
    
    // teste OP2
    list_insert(&l1, 50);
   
    // teste OP3
    list_insert_at(&l1, 20, 1);

    if(!list_equals(&l1, &l2)) {
        printf("[FAIL] test_from_1_to_3\n");
        printf("expected: ");
        list_print(&l2);

        printf("received: ");
        list_print(&l1);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_from_1_to_3\n");
}

void test_4() {
    List l1 = list();
    List l2 = {
        items: { 2, 5, 10, 42, 50, 100 },
        length: 6
    };

    list_insert_sorted(&l1, 5);
    list_insert_sorted(&l1, 50);
    list_insert_sorted(&l1, 2);
    list_insert_sorted(&l1, 100);
    list_insert_sorted(&l1, 10);
    list_insert_sorted(&l1, 42);

    if(!list_equals(&l1, &l2)) {
        printf("[FAIL] test_4\n");
        printf("expected: ");
        list_print(&l2);

        printf("received: ");
        list_print(&l1);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_4\n");
}

void test_5_and_6() {
    List l1 = {
        items: { 10, 20, 30, 40, 50 },
        length: 5
    };

    list_show(&l1);
    list_show_reverse(&l1);
}

void test_from_7_to_10() {
    List l1 = {
        items: { 12, 56, 5, 10, 50, 100, 500, 600 },
        length: 8
    };
    List l2 = list();
    List expectedList = {
        items: { 5, 10 },
        length: 2
    };

    // do nothing
    list_remove_at(&l2, 7);
    list_remove_at(&l2, 0);
    list_remove_at(&l1, 999);
    list_remove_at(&l1, -1);
    list_remove(&l1, 27);

    // it removes
    list_remove_at(&l1, 4);
    list_remove(&l1, 12);
    list_remove_first(&l1);
    list_remove(&l1, 100);
    list_remove_last(&l1);
    list_remove(&l1, 500); 

    if(!list_equals(&l1, &expectedList)) {
        printf("[FAIL] test_from_7_to_10\n");
        printf("expected: ");
        list_print(&expectedList);

        printf("received: ");
        list_print(&l1);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_from_7_to_10\n");
}

void test_11() {
    List l1 = {
        items: { 5, 10, 42, 50, 100 },
        length: 5
    };
    List resultList = list();
    List expectedResultList = list();

    list_insert(&resultList, list_linear_search(&l1, 42));
    list_insert(&expectedResultList, 2);

    if(!list_equals(&resultList, &expectedResultList)) {
        printf("[FAIL] test_11\n");
        printf("expected: ");
        list_print(&expectedResultList);

        printf("received: ");
        list_print(&resultList);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_11\n");
}

void test_12() {
    List l1 = {
        items: { 0, 2, 10, -2, 7 },
        length: 5
    };
    int expected = 17;
    int result = list_sum(&l1);

    if(result != expected) {
        printf("[FAIL] test_12\n");
        printf("expected: %d", expected);

        printf("received: %d", result);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_12\n");
}

void test_14() {
    List l1 = {
        items: { 0, 2, 10, -2 },
        length: 4
    };
    List expectedList = {
        items: { 0, 4, 100, 4 },
        length: 4
    };

    list_squared(&l1);

    if(!list_equals(&l1, &expectedList)) {
        printf("[FAIL] test_14\n");
        printf("expected: ");
        list_print(&expectedList);

        printf("received: ");
        list_print(&l1);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_14\n");
}

void test_15() {
    List l1 = {
        items: { 0, 1, 2, 3, 200, 103, 50, 257 },
        length: 8
    };
    int expected = 4;
    int result = list_prime_amount(&l1);

    if(result != expected) {
        printf("[FAIL] test_15\n");
        printf("expected: %d", expected);

        printf("received: %d", result);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_15\n");
}

void test_list_bubble_sort() {
    List l1 = {
        items: { 2, 3, 1, 200, 103, 50, 257, 10 },
        length: 8
    };
    List expectedList = {
        items: { 1, 2, 3, 10, 50, 103, 200, 257 },
        length: 8
    };

    list_bubble_sort(&l1);

    if(!list_equals(&l1, &expectedList)) {
        printf("[FAIL] test_list_bubble_sort\n");
        printf("expected: ");
        list_print(&expectedList);

        printf("received: ");
        list_print(&l1);
        exit(TEST_ERROR);
    }

    printf("[SUCCESS] test_list_bubble_sort\n");
}

void run_tests(List *list) {
    system("clear");
    test_from_1_to_3();
    test_4();
    // test_5_and_6();
    test_from_7_to_10();
    test_11();
    test_12();
    test_14();
    test_15();
    test_list_bubble_sort();
    exit(0);
}

typedef void Action(List *list);

void header_plus(List *list, char title[], int clear) {
    if (!DEBUG_MODE || clear) {
        system("clear");
    }

    printf("===============================\n");
    printf("%s\n", &title[0]);
    printf("===============================\n");
    list_show(list);
    printf("Tamanho: %d%s\n\n", list->length, (list->length == MAX ? " (lista cheia)" : " "));
}

void header(List *list, char text[]) {
    header_plus(list, text, 1);
}

int get_integer_from_keyboard(char message[]) {
    int result;
    int is_invalid;
    do {
        printf("%s", message);
        is_invalid = scanf("%d", &result) != 1;
        while(is_invalid && getchar() != EOF && getchar() != '\n');
    } while (is_invalid);

    return result;
}

void handle_view(int code, List *list) {
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

void choice_option(Options *options, List *list) {
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

void view_insert_first(List *list) {
    header(list, "INSERIR NO INICIO");
    handle_view(list_insert_first(list, get_integer_from_keyboard(TEXT_DN)), list);
}

void view_insert(List *list) {
    header(list, "INSERIR NO FIM");
    handle_view(list_insert(list, get_integer_from_keyboard(TEXT_DN)), list);
}

void view_list_insert_at(List *list) {
    header(list, "INSERIR NUMA POSIÇÃO ESPECÍFICA");
    int value = get_integer_from_keyboard(TEXT_DN);
    int index = get_integer_from_keyboard(TEXT_DP);
    handle_view(list_insert_at(list, value, index), list);
}

void view_list_insert_sorted(List *list) {
    list_bubble_sort(list);
    header(list, "ORDENAR LISTA E INSERIR VALOR QUALQUER");
    handle_view(list_insert_sorted(list, get_integer_from_keyboard(TEXT_DN)), list);
}

void view_list_show_reverse(List *list) {
    printf("Lista reversa: ");
    list_show_reverse(list);
    header_plus(list, TEXT_LS, 0);
}

void view_list_remove_last(List *list) {
    handle_view(list_remove_last(list), list);
}

void view_list_remove_first(List *list) {
    handle_view(list_remove_first(list), list);
}

void view_list_remove_at(List *list) {
    header(list, "REMOVER ITEM DE UMA POSIÇÃO ESPECÍFICA");
    handle_view(list_remove_at(list, get_integer_from_keyboard(TEXT_DP)), list);
}

void view_list_remove(List *list) {
    header(list, "REMOVER UM VALOR ESPECÍFICO");
    handle_view(list_remove(list, get_integer_from_keyboard(TEXT_DN)), list);
}

void view_list_linear_search(List *list) {
    header(list, "BUSCAR UM VALOR ESPECÍFICO");
    int value = get_integer_from_keyboard(TEXT_DN);
    int result = list_linear_search(list, value);
    system("clear");

    if (result == -1) {
        printf("%d não existe na lista.\n", value);
    } else {
        printf("%d encontrado na posição %d.\n", value, result);
    }

    header_plus(list, TEXT_LS, 0);
}

void view_list_sum(List *list) {
    printf("Soma dos valores da lista: %d\n", list_sum(list));
    header_plus(list, TEXT_LS, 0);
}

void view_list_squared(List *list) {
    list_squared(list);
    header_plus(list, TEXT_LS, 0);
}

void view_list_prime_amount(List *list) {
    printf("Quantidade de números primos da lista: %d\n", list_prime_amount(list));
    header_plus(list, TEXT_LS, 0);
}

void view_list_bubble_sort(List *list) {
    list_bubble_sort(list);
    header_plus(list, TEXT_LS, 0);
}

void exit_list(List *list) {
    system("clear");
    printf("Lista final: \n");
    list_show(list);
    exit(0);
}

void main() {
    List main_list = list();
    // List main_list = {
    //     items: { 2, 5, 3, 4 },
    //     length: 4
    // };

    Options options = {
        { code: 1, description: "1 - Inserir no inicio", action: view_insert_first },
        { code: 2, description: "2 - Inserir no fim", action: view_insert },
        { code: 3, description: "3 - Inserir numa posição específica", action: view_list_insert_at },
        { code: 4, description: "4 - Ordenar lista e inserir valor(mantendo ordenação) ", action: view_list_insert_sorted }, 
        { code: 6, description: "6 - Mostrar lista reversa", action: view_list_show_reverse }, 
        { code: 7, description: "7 - Remover item do fim da lista", action: view_list_remove_last },
        { code: 8, description: "8 - Remover item do inicio da lista", action: view_list_remove_first },
        { code: 9, description: "9 - Remover item de uma posição específica", action: view_list_remove_at },
        { code: 10, description: "10 - Remover item um valor específico", action: view_list_remove },
        { code: 11, description: "11 - Buscar um valor específico", action: view_list_linear_search },
        { code: 12, description: "12 - Somar todos os valores da lista", action: view_list_sum },
        { code: 13, description: "13 - Elevar ao quadrado todos os valores da lista", action: view_list_squared },
        { code: 15, description: "15 - Contar a quantidade de números primos da lista", action: view_list_prime_amount },
        { code: 16, description: "16 - Ordenar a lista", action: view_list_bubble_sort },
        { code: 42, description: "42 - Rodar testes e sair", action: run_tests },
        { code: 99, description: "99 - Sair", action: exit_list },
    };

    header(&main_list, TEXT_LS);
    choice_option(&options, &main_list);
}
