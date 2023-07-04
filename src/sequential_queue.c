#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "sequential_list.h"

typedef List *QueueList;

Queue create_queue() {
    QueueList queue_list = (QueueList) malloc(sizeof(QueueList));
    queue_list->length = 0;

    Queue queue = {
        size: 0,
        data: queue_list
    };

    return queue;
}

void enqueue(Queue *queue, int value) {
    QueueList queue_list = (QueueList) queue->data;
    queue_list->length = queue->size;
    int success = list_insert(queue_list, value);
    if (success) {
        queue->size++;
        queue_list->length = queue->size;
    }
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        return 0;
    }

    QueueList queue_list = (QueueList) queue->data;
    queue_list->length = queue->size;

    int first_item = queue_list->items[0];
    int success = list_remove_first(queue_list);
    if (success) {
        queue->size--;
        queue_list->length = queue->size;
        return first_item;
    }

    return 0;
}

int peek(Queue *queue) {
    if (queue->size == 0) {
        return 0;
    }

    QueueList queue_list = (QueueList) queue->data;
    queue_list->length = queue->size;
    return queue_list->items[0];
}

int is_empty(Queue *queue) {
    return queue->size == 0;
}

void print_queue(Queue *queue) {
    QueueList queue_list = (QueueList) queue->data;
    list_show(queue_list);
    queue_list->length = queue->size;
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
