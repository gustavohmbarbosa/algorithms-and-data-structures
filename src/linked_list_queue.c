#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "linked_list.h"

typedef LinkedList *QueueList;

Queue create_queue() {
    QueueList queue_list = (QueueList) malloc(sizeof(QueueList));
    Queue queue = { 
        size: 0,
        data: queue_list
    };
    
    return queue;
}

void enqueue(Queue *queue, int value) {
    linked_list_add((QueueList) queue->data, value);
    queue->size++;
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        return 0;
    }

    QueueList queue_list = (QueueList) queue->data;
    int first_one = (*queue_list)->value;
    linked_list_remove_first_one(queue_list);
    queue->size--;

    return first_one;
}

int peek(Queue *queue) {
        if (is_empty(queue)) {
        return 0;
    }

    QueueList queue_list = (QueueList) queue->data;

    return (*queue_list)->value;
}

int is_empty(Queue *queue) {
    return queue->size == 0;
}

void print_queue(Queue *queue) {
    if (is_empty(queue)) {
        printf("[]\n");
        return;
    }

    linked_list_show((QueueList) queue->data);
}

void main() {
    Queue queue = create_queue();
    QueueList queue_list = (QueueList) queue.data;
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    print_queue(&queue); // [10, 20, 30]

    printf("dequeue: %d | size: %d\n", dequeue(&queue), queue.size); // 10
    printf("dequeue: %d | size: %d\n", dequeue(&queue), queue.size); // 20
    printf("dequeue: %d | size: %d\n", dequeue(&queue), queue.size); // 30
    printf("dequeue: %d | size: %d\n", dequeue(&queue), queue.size); // 0
    printf("dequeue: %d | size: %d\n", dequeue(&queue), queue.size); // 0

    enqueue(&queue, 19);
    enqueue(&queue, 42);
    print_queue(&queue); // [19, 42]

    printf("peek: %d | size: %d\n", peek(&queue), queue.size); // 19
    printf("dequeue: %d | size: %d\n", dequeue(&queue), queue.size); // 19
    printf("dequeue: %d | size: %d\n", dequeue(&queue), queue.size); // 42
    printf("dequeue: %d | size: %d\n", dequeue(&queue), queue.size); // 0
    print_queue(&queue); // []
}
