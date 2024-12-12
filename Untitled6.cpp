#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Deque {
    int arr[MAX];
    int front, rear;
};

void initDeque(struct Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(struct Deque* dq) {
    return dq->front == -1;
}

int isFull(struct Deque* dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->rear == dq->front - 1);
}

void addFront(struct Deque* dq, int data) {
    if (isFull(dq)) {
        printf("Hang doi hai dau day! Khong them duoc phan tu.\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = data;
    printf("Them phan tu vao dau: %d\n", data);
}

void addRear(struct Deque* dq, int data) {
    if (isFull(dq)) {
        printf("Hang doi hai dau day! Khong them duoc phan tu.\n");
        return;
    }

    if (dq->rear == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = data;
    printf("Them phan tu vao cuoi: %d\n", data);
}

void removeFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Hang doi hai dau rong! Khong co phan tu de lay ra.\n");
        return;
    }

    printf("Lay ra phan tu tu dau: %d\n", dq->arr[dq->front]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void removeRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Hang doi hai dau rong! Khong co phan tu de lay ra.\n");
        return;
    }

    printf("Lay ra phan tu tu cuoi: %d\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

void printDeque(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Hang doi hai dau rong.\n");
        return;
    }

    printf("Hang doi hien tai: [");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d, ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d]\n", dq->arr[dq->rear]);
}

int main() {
    struct Deque dq;
    initDeque(&dq);

    addFront(&dq, 10);
    addRear(&dq, 20);
    addFront(&dq, 5);

    printDeque(&dq);

    removeFront(&dq);
    printDeque(&dq);

    removeRear(&dq);
    printDeque(&dq);

    return 0;
}

