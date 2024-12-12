#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

struct Task {
    int priority;
    char data[50];
};

struct PriorityQueue {
    struct Task arr[MAX];
    int size;
};

void initQueue(struct PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}

void enqueue(struct PriorityQueue* pq, int priority, const char* data) {
    if (pq->size == MAX) {
        printf("Hang doi uu tien day! Khong them duoc phan tu.\n");
        return;
    }

    struct Task newTask;
    newTask.priority = priority;
    strcpy(newTask.data, data);

    int i = pq->size - 1;
    while (i >= 0 && pq->arr[i].priority > newTask.priority) {
        pq->arr[i + 1] = pq->arr[i];
        i--;
    }

    pq->arr[i + 1] = newTask;
    pq->size++;
    printf("Them phan tu (%d, \"%s\"): Hang doi khong rong\n", priority, data);
}

void dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hang doi uu tien rong! Khong co phan tu de lay ra.\n");
        return;
    }

    printf("Lay ra phan tu: \"%s\" (uu tien %d)\n", pq->arr[0].data, pq->arr[0].priority);
    for (int i = 0; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
}

void peek(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hang doi uu tien rong! Khong co phan tu de tra ve.\n");
        return;
    }

    printf("Phan tu uu tien cao nhat: \"%s\" (uu tien %d)\n", pq->arr[0].data, pq->arr[0].priority);
}

int main() {
    struct PriorityQueue pq;
    initQueue(&pq);

    enqueue(&pq, 2, "Task A");
    enqueue(&pq, 1, "Task B");
    enqueue(&pq, 3, "Task C");

    peek(&pq);
    dequeue(&pq);

    peek(&pq);
    dequeue(&pq);

    return 0;
}

