#include "Queue.h"
#include <stdio.h>

Queue *createQueue(void)
{
    Queue *newQueue;

    newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL;
    newQueue->size = 0;

    return (newQueue);
}


Queue *copyQueue(Queue *queue)
{
    Queue *copyQueue;
s
    copyQueue = (Queue *)malloc(sizeof(queue));
    copyQueue->front = queue->front;
    copyQueue->rear = queue->rear;
    copyQueue->size = queue->size;

    return (copyQueue);
}


size_t size(Queue *Queue)
{
    if (Queue == NULL)
        return 0;

    return (Queue->size);
}

bool isEmptyQueue(Queue *Queue)
{
    if (Queue == NULL)
        return 0;

    if (Queue->size == 0)
        return (true);

    return (false);
}

bool enqueue(Queue *Queue, int value) // 큐가 공백일 때 + 공백 아닐 때
{
    if (Queue == NULL)
        return (false);

    ListNode *addNode = (ListNode *)malloc(sizeof(ListNode));

    addNode->value = value;
    addNode->prev = addNode->next = NULL;

    if (isEmptyQueue(Queue))
    {
        Queue->front = addNode;
        Queue->rear->next = addNode;
    }

    Queue->rear = addNode;
    Queue->size++;

    return (true);
}


int dequeue(Queue *Queue) // 반환형int로 변경, 노드 개수가 1개일 때 + 여러 개일 때
{
    if (Queue == NULL)
        return 0;

    ListNode *tmpNode;
    int data = 0;

    if (isEmptyQueue(Queue))
        return 0;
    else
    {
        tmpNode = Queue->front;
        data = tmpNode->value;
        Queue->front = tmpNode->next;
        Queue->front->prev = NULL;
        if (Queue->front == NULL) // 노드가 1개뿐이었다가 삭제되었을 때
            Queue->rear = NULL;
        free(tmpNode);
    }

    return (data);
}


int peek(Queue *Queue)
{
    if (Queue == NULL)
        return 0;

    return (Queue->front->value);
}

void clearQueue(Queue *Queue)
{
    if (Queue == NULL)
        return;

    ListNode *tmpNode = Queue->rear;
    size_t i = 0;

    while (i < Queue->size)
    {
        tmpNode = Queue->rear->prev;
        Queue->rear = Queue->rear->prev;
        free(tmpNode->next);
        i++;
    }
    Queue->size = 0;
}

void destroyQueue(Queue *Queue)
{
    if (Queue == NULL)
        return;
    
    if (Queue->size != 0)
        clearQueue(Queue);
    free(Queue);
}