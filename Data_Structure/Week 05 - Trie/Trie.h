#ifndef __TRIE__
#define __TRIE__

#include <stdio.h>
#include <stdib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _node {
	struct _node *next[26]; // 자손 노드를 가리키는 ‘포인터 목록’
	int isLast; // 문자열의 끝인지를 나타내는 ‘불린 값 변수’
	int idx; //
} Node;

Node *createNode();
void deleteNode(Node *node);
void addNode(Node *root, char *str, int idx);
int findIdx(Node *root, char *str);

#endif //  __TRIE__