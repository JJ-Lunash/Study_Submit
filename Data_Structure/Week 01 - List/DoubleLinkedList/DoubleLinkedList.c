#include "DoubleLinkedList.h"

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
            List->size += 1; // while문 밖에있다가 수정
            return (true);
        }
        midNode = midNode->next;
        i++;
    }

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
        List->size += 1; // 새로 추가
        return (true);
    }
    else
    {
        List->head->prev = node;
        node->prev == NULL;
        node->next = List->head;
        List->head = node; // List = node에서 수정
        List->size += 1; // 새로 추가
        return (true);
    }

    return (false); // return (true)였다가 if,else문에 각각 넣어주고 수정
}


bool addNodeToTail(DoubleLinkedList *List, ListNode *node)
// 리스트에 아무것도 없는 상황 + 이미 있는데 추가하는 상황
{
    ListNode *tailNode;

    if (List->head == NULL)
    {
        List->head = List->tail = node;
        node->prev = node->next = NULL;
        List->size = 1; // 새로 추가
        return (true);
    }

    else
    {
        tailNode = List->head;
        while(tailNode->next != NULL) // tailNode != NULL에서 수정
            tailNode = tailNode->next;
        tailNode->next = node;
        node->prev = tailNode;
        node->next = NULL; // 새로 추가
        List->size += 1; // 새로 추가
        return (true);
    }

    return (false); // addNodeToHead 함수와 동일하게 수정
}


bool removeNodeByIndex(DoubleLinkedList *List, int index)
{
    ListNode *tmpNode = List->head;
    int i = 0;

    if (List == NULL || index >= List->size) // if문 예외처리 새로 추가 , index > 에서 수정
        return (false);

    while (tmpNode != NULL)
    {
        if (i == index) // if문 안에 새로 완성
        {
            tmpNode->prev->next = tmpNode->next;
            tmpNode->next->prev = tmpNode->prev;
            tmpNode->prev = tmpNode->next = NULL; // 여기 관련 중요 메모 맨 밑에 적어두기 (제목:동적할당 free)
            free (tmpNode);
            List->size -= 1;
            return (true);
        }
        tmpNode = tmpNode->next;
        i++;
    }

    return (false); // return문 위 함수들과 동일하게 수정
}


bool removeHeadNode(DoubleLinkedList *List)
{
    ListNode *tmpNode = List->head->next;

    //List 자체가 아예 존재하지 않을 때, List 틀은 있으나 node가 존재하지 않을 때, node가 1개만 존재할 때 경우 통으로 추가
    if (List == NULL)
        return (false);

    else if (List->size == 1)
    {
        free(List->head);
        free(List->tail);
        List->size = 0;
        return (true);
    }

    else /////////////////////////////여기 다시보자!
    {
        tmpNode->prev = NULL;
        List->head->next = NULL;
        free (List->head); // 이거랑 이 밑에 줄 맞나...
        List->head = tmpNode;
        return (true);
    }

    List->head = List->head->next;
    free(List->head->prev);
    List->head->prev == NULL;

    return (true);
}


bool removeTailNode(DoubleLinkedList *List)////////이거도다시봦!!!!!!!!!
{
    List->tail = List->tail->prev;
    free(List->tail->next);
    List->tail->next;
}


ListNode *getNodeByIndex(DoubleLinkedList *List, int index)
{
    ListNode *findNode = List->head;
    int i = 0;

    if (List == NULL || index >= List->size)
        return (NULL);

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
    if (List == NULL)
        reutrn (NULL);

    return (List->head);
}


ListNode *getLastNode(DoubleLinkedList *List)
{
    ListNode *tmpNode = List->head;

    if (List == NULL)
        return (NULL);

    while (tmpNode->next != NULL)
        tmpNode = tmpNode -> next;
    
    return (tmpNode);
}


int getValueByIndex(DoubleLinkedList *List, int index)
{
    ListNode *findNode = List->head;
    int i = 0;

    if (List == NULL || index >= List->size)
        return 0;

    while (findNode != NULL)
    {
        if (i++ == index)
            return (findNode->Value);
        findNode = findNode->next;
    }

    return 0;
}


size_t getSizeDoubleLinkedList(DoubleLinkedList *List)
{
    size_t i = 0;
    ListNode *cntNode = List->head;

    if (List == NULL)
        return 0;

    while (cntNode != NULL)
    {
            cntNode = cntNode->next;
            i++;
    }

    return (i);
}


bool isEmptyDoubleLinkedList(DoubleLinkedList *List)
{
    if (List == NULL || List->size == 0)
        return (true);
    
    return (false);
}


void displayDoubleLinkedList(DoubleLinkedList *List)
{

    ListNode *tmpNode = List->head;
    int val = tmpNode->Value;

    if (List == NULL || List->size == 0)
        return;

    while (tmpNode->next != NULL)
    {
        printf("%d", val);
        printf(", ");
        tmpNode = tmpNode->next;
    }
    printf("%d", val); // val 해결하기!!!
}


void clearDoubleLinkedList(DoubleLinkedList *List)
{
    if (List == NULL)
        return;

    ListNode *tmpNode = List->head;

    while (tmpNode != NULL)
    {
        List->head->next = NULL;
        tmpNode->next->prev = NULL;
        free(List->head);
        List->head = tmpNode;
        tmpNode = tmpNode->next;
    }
}


void distroyDoubleLinkedList(DoubleLinkedList *List)
{
    if (List == NULL)
        return;

    ListNode *tmpNode = List->head;

    while (tmpNode != NULL)
    {
        List->head->next = NULL;
        tmpNode->next->prev = NULL;
        free(List->head);
        List->head = tmpNode;
        tmpNode = tmpNode->next;
    }
    tmpNode->prev = NULL;
    free(tmpNode);
}