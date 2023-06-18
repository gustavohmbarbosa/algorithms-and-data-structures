#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
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
