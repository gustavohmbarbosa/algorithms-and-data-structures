#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

/*
 * https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/chocolate-stack-746c1b56/?purpose=login&source=problem-page&update=google
 */
int* solution (int N, int* C, int* out_n) {
    *out_n = 0;
    int *result = (int*) malloc(sizeof(int)*(N));

    int stack_size = 0;
    int *stack = (int*) malloc(sizeof(int)*(N));
    
    for (int i = 0; i < N; i++) {
        if (C[i] > 0) {
            stack[stack_size] = C[i];
            stack_size++;
            continue;
        }

        if (stack_size > 0) {
            result[*out_n] = stack[stack_size - 1];
            (*out_n)++;
            stack_size--;
        }
    }

    return result;
}

int main() {
    int out_n;
    int N;
    scanf("%d", &N);
    int i_C;
    int *C = (int *)malloc(sizeof(int)*(N));
    for(i_C = 0; i_C < N; i_C++)
    	scanf("%d", &C[i_C]);

    int* out_ = solution(N, C, &out_n);
    printf("%d", out_[0]);
    for(int i_out_ = 1; i_out_ < out_n; i_out_++)
    	printf(" %d", out_[i_out_]);
}