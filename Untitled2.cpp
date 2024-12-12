#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Hang doi day! Khong them duoc phan tu.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = value;
    printf("Da them %d vao hang doi.\n", value);
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong! Khong co phan tu de xoa.\n");
        return;
    }
    printf("Da xoa %d khoi hang doi.\n", q->arr[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong! Khong co phan tu.\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    dequeue(&q);
    printQueue(&q);

    dequeue(&q);
    printQueue(&q);

    dequeue(&q);
    printQueue(&q);

    dequeue(&q);  

    return 0;
}

