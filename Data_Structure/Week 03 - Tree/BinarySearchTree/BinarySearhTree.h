#ifndef __BINARYSEARCHTREE__
#define __BINARYSEARCHTREE__

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *left;
	struct _node *right;
} Node;

Node *searchBST(Node *root, int key);
Node *insertBST(Node * root, char c);
Node *deleteBST(Node * root, char c);

#endif // __BINARYSEARCHTREE__