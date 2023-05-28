#include "forDequeue.h"

Dequeue *createAndInitDequeue(int size)
{
    Dequeue *newdq;
    newdq->dataList = (int *)malloc(sizeof(int) * size);
    memset(newdq->dataList, 0, size);
    newdq->front = newdq->rear = 0;
    newdq->maxSize = size;

    return (newdq);
}

bool is_empty(Dequeue *dq)
{
    if (dq == NULL)
        return;

    if (dq->front == dq->rear)
        return (true);

    return (false);
}

bool is_full(Dequeue *dq)
{
    if (dq == NULL)
        return;

    if ((dq->rear + 1) % dq->maxSize == dq->front)
        return (true);

    return (false);
}

void addFront(Dequeue *dq, int data)
{
    if (dq == NULL || is_empty(dq) == true)
        return;

    dq->dataList[dq->front] = data;
    dq->front = (dq->front - 1 + dq->maxSize) % dq->maxSize;
}

void addRear(Dequeue *dq, int data)
{

}

int delFront(Dequeue *dq)
{

}

int delRear(Dequeue *dq)
{

}

int getFront(Dequeue *dq)
{

}

int getRear(Dequeue *dq)
{

}