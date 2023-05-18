#include "DoubleLinkedList.h"

typedef struct _node {
    int Value; // v -> V
    struct _node *next;
    struct _node *prev;
}       ListNode;

typedef struct _DoubleLinkedList {
    struct _node *head;
    struct _node *tail;
    size_t size;
}       DoubleLinkedList;

DoubleLinkedList *createDoubleLinkedList()
{
    DoubleLinkedList *newList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    newList->head = newList->tail = NULL;
    newList->size = 0;

    return (newList);
}


DoubleLinkedList *copyDoubleLinkedList(DoubleLinkedList *List)
{
    DoubleLinkedList *copyList = (DoubleLinkedList*)malloc(sizeof(List));
    copyList->head = List->head;
    copyList->tail = List->tail;
    copyList->size = List->size;

    return (copyList);
}


ListNode *createNode(int value)
{
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->Value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (newNode);
}


bool addNode(DoubleLinkedList *List, ListNode *node, int index) 
{
    ListNode *midNode = List->head;
    int i = 1;

    while(midNode != NULL)
    {
        if (i == index)
        {
            midNode->next->prev = node; // 얘 먼저 해줘야함! 안그러면 연결고리 끊겨서 안돼
            node->next = midNode->next;
            midNode->next = node;
            node->prev = midNode;
            return (true);
        }
        midNode = midNode->next;
        i++;
    }
    List->size += 1;

    return (false);
}


bool addNodeToHead(DoubleLinkedList *List, ListNode *node)
{
    if (List == NULL || node == NULL)
        return (0);

    if(List->head == NULL)
    {
        List->head = List->tail = node;
        node->prev = NULL;
        node->next = NULL;
    }
    else
    {
        List->head->prev = node;
        node->prev == NULL;
        node->next = List->head;
        List = node;

    return (true);
    }

    reteurn (true); //////////// return 값 다시 생각하기
}


bool addNodeToTail(DoubleLinkedList *List, ListNode *node)
// 리스트에 아무것도 없는 상황 + 이미 있는데 추가하는 상황
{
    ListNode *tailNode;

    if (List->head == NULL)
        List->head == node;
    else
        tailNode = List->head;
        while(tailNode != NULL)
            tailNode = tailNode->next;

    tailNode->next = node;
    node->prev = tailNode;

    return (true); /////////////// 리턴값 다시 생각해보기!!!
}


bool removeNodeByIndex(DoubleLinkedList *List, int index)
{
    ListNode *tmpNode = List->head;
    int i = 0;

    while (tmpNode != NULL)
    {
        if (i == index)
        {

        }
        tmpNode = tmpNode->next;
        i++;
    }

    return (true);
}


bool removeHeadNode(DoubleLinkedList *List)
{
    List->head = List->head->next;
    free(List->head->prev);
    List->head->prev == NULL;

    return (true);
}


bool removeTailNode(DoubleLinkedList *List)
{
    List->tail = List->tail->prev;
    free(List->tail->next);
    List->tail->next
}


ListNode *getNodeByIndex(DoubleLinkedList *List, int index)
{
    ListNode *findNode = List->head;
    int i = 0;

    while (findNode != NULL)
    {
        if (i++ == index)
            return (findNode);
        findNode = findNode->next;
    }

    return (NULL);
}
ListNode *getHeadNode(DoubleLinkedList *List)
{

}


ListNode *getLastNode(DoubleLinkedList *List)
{

}


int getValueByIndex(DoubleLinkedList *List, int index);


size_t getSizeDoubleLinkedList(DoubleLinkedList *List)
{
    size_t i = 0;
    ListNode *cntNode = List->head;

    while (cntNode != NULL)
    {
            cntNode = cntNode->next;
            i++;
    }

    return (i);
}


bool isEmptyDoubleLinkedList(DoubleLinkedList *List);

void displayDoubleLinkedList(DoubleLinkedList *List);
void clearDoubleLinkedList(DoubleLinkedList *List);
void distroyDoubleLinkedList(DoubleLinkedList *List);