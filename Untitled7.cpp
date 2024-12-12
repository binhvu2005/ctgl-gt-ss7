#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

void initQueue(struct PriorityQueue* pq) {
    pq->front = NULL;
}

int isEmpty(struct PriorityQueue* pq) {
    return pq->front == NULL;
}

void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Khong du bo nho de them phan tu.\n");
        return;
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (isEmpty(pq) || pq->front->priority < priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Node* temp = pq->front;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Them phan tu: %d voi uu tien %d\n", data, priority);
}

void dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hang doi uu tien rong! Khong co phan tu de lay ra.\n");
        return;
    }
    struct Node* temp = pq->front;
    pq->front = pq->front->next;
    printf("Lay ra phan tu: %d voi uu tien %d\n", temp->data, temp->priority);
    free(temp);
}

void peek(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hang doi uu tien rong! Khong co phan tu de xem.\n");
        return;
    }
    printf("Phan tu uu tien cao nhat: %d voi uu tien %d\n", pq->front->data, pq->front->priority);
}

void printQueue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Hang doi uu tien rong.\n");
        return;
    }
    struct Node* temp = pq->front;
    printf("Hang doi hien tai: ");
    while (temp != NULL) {
        printf("[%d(%d)] ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    initQueue(&pq);

    enqueue(&pq, 10, 1);
    printQueue(&pq);

    enqueue(&pq, 20, 2);
    printQueue(&pq);

    enqueue(&pq, 30, 1);
    printQueue(&pq);

    dequeue(&pq);
    printQueue(&pq);

    enqueue(&pq, 40, 3);
    printQueue(&pq);

    dequeue(&pq);
    printQueue(&pq);

    return 0;
}

