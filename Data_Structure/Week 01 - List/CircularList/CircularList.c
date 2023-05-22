#include "CircularList.h"

typedef struct _node {
    int value;
    struct _node *next;
    struct _node *prev;
}       ListNode;

typedef struct _circularList {
    struct _node *head;
    size_t size;
}       CircularList;


ListNode *createNode(int value)
{
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->value = value;
    newNode->prev = newNode; // NULL에서 newNode로 수정
    newNode->next = newNode; // NULL에서 newNode로 수정

    return (newNode);
}


CircularList *createCircularList()
{
    CircularList *newList = (CircularList*)malloc(sizeof(CircularList));
    newList->head = NULL;
    newList->size = 0;

    return (newList);
}


CircularList *copyCircularList(CircularList *circularList)
{
    CircularList *copyList = (CircularList*)malloc(sizeof(circularList));
    copyList->head = circularList->head;
    copyList->size = circularList->size;

    return (copyList);
}


bool addNode(CircularList *circularList, ListNode *node, size_t index)
{
    ListNode *midNode = circularList->head;
    size_t i = 1;

    while(midNode->next != circularList->head)
    {
        if (i == index)
        {
            midNode->next->prev = node;
            node->next = midNode->next;
            midNode->next = node;
            node->prev = midNode;
            circularList->size += 1;
            return (true);
        }
        midNode = midNode->next;
        i++;
    }

    return (false);
}


bool addNodeToHead(CircularList *circularList, ListNode *node)
{
    if (circularList == NULL || node == NULL)
        return (false);

    else
    {
        if (circularList->head == NULL)
            circularList->head = node;
        else
        {
            circularList->head->prev->next = node;
            node->prev = circularList->head->prev;
            circularList->head->prev = node;
            node->next = circularList->head;
            circularList->head = node;
        }   

    return (true);
}


bool removeNodeByIndex(CircularList *circularList, size_t index)
{
    ListNode *tmpNode = circularList->head;
    size_t i = 0;

    if (circularList == NULL || index >= circularList->size)
        return (false);

    while (tmpNode->next != circularList->head)
    {
        if (i == index) // if문 안에 새로 완성
        {
            tmpNode->prev->next = tmpNode->next;
            tmpNode->next->prev = tmpNode->prev;
            tmpNode->prev = tmpNode->next = NULL;
            free (tmpNode);
            circularList->size -= 1;
            return (true);
        }
        tmpNode = tmpNode->next;
        i++;
    }

    if (tmpNode->next == circularList->head) // 마지막 노드의 경우 분리
    {
        tmpNode->prev->next = circularList->head;
        circularList->head = tmpNode->prev;
        tmpNode->prev = tmpNode->next = NULL;
        free (tmpNode);
        circularList->size -= 1;
        return (true);
    }

    return (false); // return문 위 함수들과 동일하게 수정
}


bool removeHeadNode(CircularList *circularList)
{
    if (circularList == NULL)
        return (false);

    else
    {
        circularList->head->next->prev = circularList->head->prev;
        circularList->head->prev->next = circularList->head->next;
        circularList->head = circularList->head->next;
        circularList->head->next = circularList->head->prev = NULL;
        circularList->size -= 1;
    }

    return (false);
}


/*
getNodeByIndex()를 구현할 때, 최적화를 진행해보세요.
어떻게 하면 더 적은 비용으로 노드를 찾을 수 있도록 구현할 수 있을까요? 
*/
ListNode *getNodeByIndex(CircularList *circularList, size_t index)
{
    ListNode *findNode = circularList->head;
    size_t i = 0;

    if (circularList == NULL || index >= circularList->size)
        return (NULL);

    while (findNode != NULL)
    {
        if (i++ == index)
            return (findNode);
        findNode = findNode->next;
    }

    return (NULL);
}


ListNode *getHeadNode(CircularList *circularList)
{
    if (circularList == NULL)
        return (NULL);

    return (circularList->head);
}


ListNode *getLastNode(CircularList *circularList)
{
    ListNode *tmpNode = circularList->head;

    if (circularList == NULL)
        return (NULL);

    while (tmpNode->next != circularList->head)
        tmpNode = tmpNode -> next;
    
    return (tmpNode);
}


int getValueByIndex(CircularList *circularList, size_t index)
{
    ListNode *findNode = circularList->head;
    size_t i = 0;

    if (circularList == NULL || index >= circularList->size)
        return 0;

    while (findNode != circularList->head)
    {
        if (i++ == index)
            return (findNode->value);
        findNode = findNode->next;
}


size_t getSizeCircularList(CircularList *circularList)
{
    size_t i = 0;

    if (circularList == NULL)
        return 0;

    ListNode *cntNode = circularList->head;

    while (cntNode != circularList->head)
    {
            cntNode = cntNode->next;
            i++;
    }

    return (i);
}

int displayCircularList(CircularList *circularList)
{

    ListNode *tmpNode = List->head;
    int val = tmpNode->Value;

    if (List == NULL || List->size == 0)
        return;

    while (tmpNode->next != circularList->head)
    {
        printf("%d", val);
        printf(", ");
        tmpNode = tmpNode->next;
    }
    return 0;
}

void clearCircularList(CircularList *circularList)
{
    if (circularList == NULL)
        return;

    ListNode *tmpNode = circularList->head;

    while (tmpNode != circularList->head)
    {
        circularList->head->next = NULL;
        tmpNode->next->prev = NULL;
        free(circularList->head);
        circularList->head = tmpNode;
        tmpNode = tmpNode->next;
    }
}


void distroyCircularList(CircularList *circularList)
{
    if (circularList == NULL)
        return;

    ListNode *tmpNode = circularList->head;

    while (tmpNode != NULL)
    {
        circularList->head->next = NULL;
        tmpNode->next->prev = NULL;
        free(circularList->head);
        circularList->head = tmpNode;
        tmpNode = tmpNode->next;
    }
    tmpNode->prev = NULL;
    free(tmpNode);
}