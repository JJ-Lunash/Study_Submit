#ifndef __TREE__
#define __TREE__

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int data;
    node *left;
    node *right;
} node;

node *root;
node *createNode(int data);
node* insert(node* root,int data);
node* findLowest(node* root);
node* delete(node* root,int data);
void printNode(node* root);

void preorderPrint(node* root); // 전위 순회
void inorderPrint(node* root);//중위 순회
void postorderPrint(node* root);//후위 순회

#endif // __TREE__