#include <stdio.h>
#include "queue.h"

Queue intercalate(Queue q1, Queue q2) {
    Queue result = create_queue();

    while (!is_empty(&q1) || !is_empty(&q2)) {
        if (!is_empty(&q1)) {
            enqueue(&result, dequeue(&q1));
        }

        if (!is_empty(&q2)) {
            enqueue(&result, dequeue(&q2));
        }
    }

    return result;
}

void main() {
    {
        Queue q1 = create_queue();
        enqueue(&q1, 10);
        enqueue(&q1, 20);
        enqueue(&q1, 30);
        Queue q2 = create_queue();
        enqueue(&q2, 15);
        enqueue(&q2, 25);
        enqueue(&q2, 35);

        Queue result = intercalate(q1, q2);
        print_queue(&result);
    }
    {
        Queue q1 = create_queue();
        Queue q2 = create_queue();
        enqueue(&q2, 35);

        Queue result = intercalate(q1, q2);
        print_queue(&result);
    }
}
