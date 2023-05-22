#ifndef __QUEUE__
#define __QUEUE__

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h> // 추가
#include <string.h> // 추가

typedef struct _node {
    int value;
    struct _node *prev;
    struct _node *next;
}       ListNode;

typedef struct _Queue {
    ListNode *front;
    ListNode *rear;
    size_t size;
} Queue;

Queue *createQueue(void);
Queue *copyQueue(Queue *queue);

size_t size(Queue *Queue);
bool isEmptyQueue(Queue *Queue);
bool enqueue(Queue *Queue, int value);
int dequeue(Queue *Queue);
int peek(Queue *Queue);

void clearQueue(Queue *Queue);
void destroyQueue(Queue *Queue);

#endif // __QUEUE__