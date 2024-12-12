#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Event {
    char type[50];  
    int time;       
    struct Event* next;  
};

struct EventQueue {
    struct Event* front;  
    struct Event* rear;   
};

void initQueue(struct EventQueue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(struct EventQueue* queue) {
    return queue->front == NULL;
}

void enqueue(struct EventQueue* queue, char* eventType, int time) {
    struct Event* newEvent = (struct Event*)malloc(sizeof(struct Event));
    if (!newEvent) {
        printf("Khong du bo nho de them su kien.\n");
        return;
    }
    strcpy(newEvent->type, eventType);
    newEvent->time = time;
    newEvent->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newEvent;
    } else {
        queue->rear->next = newEvent;
        queue->rear = newEvent;
    }
    printf("Them su kien: \"%s\" tai thoi gian %d\n", eventType, time);
}

void dequeue(struct EventQueue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong! Khong co su kien de xu ly.\n");
        return;
    }
    struct Event* temp = queue->front;
    queue->front = queue->front->next;
    printf("Xu ly su kien: \"%s\" tai thoi gian %d\n", temp->type, temp->time);
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;  
    }
}

void printQueue(struct EventQueue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi hien tai rong.\n");
        return;
    }
    struct Event* temp = queue->front;
    printf("Hang doi hien tai: ");
    while (temp != NULL) {
        printf("\"%s\"(%d) ", temp->type, temp->time);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct EventQueue queue;
    initQueue(&queue);

    enqueue(&queue, "Su kien A", 1);
    printQueue(&queue);

    enqueue(&queue, "Su kien B", 2);
    printQueue(&queue);

    dequeue(&queue);
    printQueue(&queue);

    enqueue(&queue, "Su kien C", 3);
    printQueue(&queue);

    dequeue(&queue);
    printQueue(&queue);

    return 0;
}

