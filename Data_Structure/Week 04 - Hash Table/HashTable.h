#ifndef __HASHTABLE__
#define __HASHTABLE__

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int value;
    struct _node *next;
} Node;

typedef struct bucket {
    Node *head;
    int count;
} Bucket;

Bucket *hashTable = NULL;
int SIZE = 10; // just example size

int hashFunction(int key);

Node *createNode(int key, int value);
void insert(int key, int value);
void remove(int key);
void search(int key);
void display();


#endif // __HASHTABLE__