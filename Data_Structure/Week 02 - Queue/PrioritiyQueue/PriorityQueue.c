#include "PriorityQueue.h"

PriorityQueue *createPriorityQueue(void)
{

}


PriorityQueue *copyPriorityQueue(PriorityQueue *PriorityQueue)
{

}


PriorityQueueNode *createPriorityQueueNode(int value, int priority)
{

}


size_t size(PriorityQueue *PriorityQueue);
bool isEmpty(PriorityQueue *PriorityQueue);
bool enqueue(PriorityQueue *PriorityQueue, int value, int priority);
bool dequeue(PriorityQueue *PriorityQueue);
int peek(PriorityQueue *PriorityQueue);

void clearPriorityQueue(PriorityQueue *PriorityQueue);
void destroyPriorityQueue(PriorityQueue *PriorityQueue);