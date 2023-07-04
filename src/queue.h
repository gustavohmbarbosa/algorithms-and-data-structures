#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    void *data;
    int size;
} Queue;

Queue create_queue();

// Adiciona um elemento no fim da fila (enfileirar)
void enqueue(Queue *queue, int value);

// Retira um elemento do início da fila (desenfileirar)
int dequeue(Queue *queue);

// Consulta o valor do primeiro elemento da fila, mas não remove.
int peek(Queue *queue);

// Retorna 1 caso a fila esteja vazia e 0 em caso contrário.
int is_empty(Queue *queue);

void print_queue(Queue *queue);

#endif