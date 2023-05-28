#ifndef __DOUBLELINKEDLIST__
#define __DOUBLELINKEDLIST__

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h> // malloc을 위해 추가

typedef struct _node {
    int Value;
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

bool addNode(DoubleLinkedList *List, ListNode *node, size_t index); // int -> size_t 수정
bool addNodeToHead(DoubleLinkedList *List, ListNode *node);
bool addNodeToTail(DoubleLinkedList *List, ListNode *node);
bool removeNodeByIndex(DoubleLinkedList *List, size_t index); // int -> size_t 수정
bool removeHeadNode(DoubleLinkedList *List);
bool removeTailNode(DoubleLinkedList *List);

ListNode *getNodeByIndex(DoubleLinkedList *List, size_t index); // int -> size_t 수정
ListNode *getHeadNode(DoubleLinkedList *List);
ListNode *getLastNode(DoubleLinkedList *List);

int getValueByIndex(DoubleLinkedList *List, size_t index); // int -> size_t 수정

size_t getSizeDoubleLinkedList(DoubleLinkedList *List);
bool isEmptyDoubleLinkedList(DoubleLinkedList *List);

int displayDoubleLinkedList(DoubleLinkedList *List); //void로는 how?
void clearDoubleLinkedList(DoubleLinkedList *List);
void distroyDoubleLinkedList(DoubleLinkedList *List);

#endif // __DOUBLELINKEDLIST__