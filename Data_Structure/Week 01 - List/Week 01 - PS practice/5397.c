#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE    1
#define FALSE   0

typedef char Data;

typedef struct _node {
    Data data;
    struct _node *next; // 여기서부터 걍 Node로 쓰면 되는 줄 알았는데 "unknown type name ‘Node’" 라는 오류가 나네
    struct _node *prev;
} Node;

typedef struct _dbLinkedList {
    Node *head;
    Node *tail;
    Node *cursor;
    int dataNum;
} DBLinkedList;

typedef DBLinkedList List; // 굳이 필수는 아니지만 그냥 편의를 위하여

void listInit(List *list)
{
    list->dataNum = 0;

    list->head = (Node *)malloc(sizeof(Node));
    list->tail = (Node *)malloc(sizeof(Node));

    list->head->prev = NULL;
    list->head->next = list->tail;

    list->tail->next = NULL;
    list->tail->prev = list->head;
}

void addFrontOfTail(List *list, Data data) //LInsert 함수
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = list->tail->prev;
    (list->tail->prev)->next = newNode;
    newNode->next = list->tail;
    list->tail->prev = newNode;

    (list->dataNum)++;
}

void addNextOfCursor(List *list, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = list->cursor;
    newNode->next = list->cursor->next;
    (list->cursor->next)->prev = newNode;
    list->cursor->next = newNode;
    list->cursor = newNode;

    (list->dataNum)++;
}

int Lfirst(List* list, Data* data)
{
	if (list->head->next == list->tail)
		return (FALSE);

	list->cursor = list->head->next;
	*data = list->cursor->data;
	return TRUE;
}

int Llast(List* list, Data* data)
{
	if (list->head->next == list->tail)
		return (FALSE);

	list->cursor = list->tail->prev;
	*data = list->cursor->data;
	return (TRUE);
}

int LNext(List* list, Data* data)
{
	if (list->cursor->next == list->tail)
		return FALSE;

	list->cursor = list->cursor->next;
	*data = list->cursor->data;
	return TRUE;
}

// /////////////////////////////////////////////////////////////////


int cursorGoLeft(List *list, Data *data) // 왜 반환형 int?
{
    if (list->cursor->prev == NULL) // 이 문장에서 list->head->prev로 써도되지 않나?
        return (FALSE);


    list->cursor = list->cursor->prev;
    *data = list->cursor->data;

    return (TRUE);
}

int cursorGoRight(List *list, Data *data) // 왜 반환형 int?
{
    if (list->cursor->next == list->tail) // 이해 제대로 못함
        return (FALSE);


    list->cursor = list->cursor->next;
    *data = list->cursor->data;

    return (TRUE);
}

void Ladd(List *list, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = list->cursor;
	newNode->next = list->cursor->next;
	(list->cursor->next)->prev = newNode;
	list->cursor->next = newNode;
	list->cursor = newNode;
	(list->dataNum)++;
}

Data removeLastNode(List *list) // 더블프리 오류 왜?
{
    Node *target = list->cursor;
    Data rm = target->data;

    (list->cursor->prev)->next = list->cursor->next;
    (list->cursor->next)->next = list->cursor->prev;

    list->cursor = list->cursor->prev;

    free(target);
    (list->dataNum)--;
    return (rm);
}

// /////////////////////////////////////////////////////////////////


void cursorLeft(List *list)
{
    Data data;
    cursorGoLeft(list, &data);
}

void cursorRight(List* list)
{
	Data data;
	cursorGoRight(list, &data);
}

void delChar(List *list)
{
    if (list->cursor == list->head)
        return;
    removeLastNode(list);
}

void addCharisCursor(List *list, char ch)
{
    Ladd(list, ch);
}

// /////////////////////////////////////////////////////////////////

void printList(List* list) // 이해는 드디어 한 것 같은데 왜이렇게 쓰는지
{
	Data data;
	if (Lfirst(list, &data))
    {
		printf("%c", data);
		while (LNext(list, &data))
			printf("%c", data);
	}
}


int main(void) {
	int caseNum, i = 0, len, j;
	List* list;
	char* str;

	scanf("%d", &caseNum);
	list = (List*)malloc(sizeof(List) * caseNum);

	while (i < caseNum)
    {
		str = (char*)malloc(sizeof(char) * 1000000);
		listInit(&list[i]);
		list[i].cursor = list[i].head;
		scanf("%s", str);
		len = strlen(str);
		while (j < len)
        {
			if (str[j] == '-') {
				delChar(&list[i]);
			}
			else if (str[j] == '<') {
				cursorLeft(&list[i]);
			}
			else if (str[j] == '>') {
				cursorRight(&list[i]);
			}
			else {
				addCharisCursor(&list[i], str[j]);
			}
            j++;
		}
		printList(&list[i]);
		printf("\n");
        i++;
	}

    return 0;
}