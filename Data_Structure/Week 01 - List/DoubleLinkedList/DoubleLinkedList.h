#ifndef __DOUBLELINKEDLIST__
#define __DOUBLELINKEDLIST__

#include <stdbool.h>
#include <stddef.h>

typedef struct _node {
    int value;
    struct _node *next;
    struct _node *prev;
}       ListNode;

typedef struct _DoubleLinkedList {
    struct _node *head;
    struct _node *tail;
    size_t size;
}       DoubleLinkedList;

DoubleLinkedList *createDoubleLinkedList();
DoubleLinkedList *copyDoubleLinkedList(DoubleLinkedList *List);
ListNode *createNode(int value);

bool addNode(DoubleLinkedList *List, ListNode *node, int index);
bool addNodeToHead(DoubleLinkedList *List, ListNode *node);
bool addNodeToTail(DoubleLinkedList *List, ListNode *node);
bool removeNodeByIndex(DoubleLinkedList *List, int index);
bool removeHeadNode(DoubleLinkedList *List);
bool removeTailNode(DoubleLinkedList *List);

ListNode *getNodeByIndex(DoubleLinkedList *List, int index);
ListNode *getHeadNode(DoubleLinkedList *List);
ListNode *getLastNode(DoubleLinkedList *List);

int getValueByIndex(DoubleLinkedList *List, int index);

size_t getSizeDoubleLinkedList(DoubleLinkedList *List);
bool isEmptyDoubleLinkedList(DoubleLinkedList *List);

void displayDoubleLinkedList(DoubleLinkedList *List);
void clearDoubleLinkedList(DoubleLinkedList *List);
void distroyDoubleLinkedList(DoubleLinkedList *List);

#endif // __DOUBLELINKEDLIST__