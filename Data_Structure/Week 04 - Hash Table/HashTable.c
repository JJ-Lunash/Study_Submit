#include "HashTable.h"

int hashFunction(int key){
    return (key%SIZE);
}


Node *createNode(int key, int value){
    Node *newNode;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    return (newNode);
}


void insert(int key, int value){
    int hashIdx = hashFunction(key);
    Node *newNode = createNode(key, value);

    // 내가 넣고자하는 인덱스에 값이 없는 경우
    if (hashTable[hashIdx].count == 0){
        hashTable[hashIdx].head = newNode;
        hashTable[hashIdx].count = 1;
    }

    // 내가 넣고자하는 인덱스에 값이 있는 경우
    else{
        newNode->next = hashTable[hashIdx].head;
        hashTable[hashIdx].head = newNode;
        hashTable[hashIdx].count++;
    }

    return;
}


void remove(int key){
    int hashIdx = hashFunction(key);
    Node *tmpNode;
    Node *traceNode; // double이 아닌 single linked list 를 사용해 구현 중이므로 필요한 아이

    tmpNode = hashTable[hashIdx].head;

    if (tmpNode == NULL){
        printf("\nno key found");
        return;
    }

    while (tmpNode != NULL){
        // key를 찾음
        if (tmpNode->key == key){
            // 아래의 if-else 묶음 : 포인터를 바꿔주는 역할
            if (tmpNode == hashTable[hashIdx].head)
                hashTable[hashIdx].head = tmpNode->next;
            else
                traceNode->next = tmpNode->next;

            hashTable[hashIdx].count--;
            free(tmpNode);
            break;
        }
        traceNode = tmpNode;
        tmpNode = tmpNode->next;
    }
    // key를 못 찾음
    printf("\nnot key found");

    return;
}


void search(int key){
    int hashInx = hashFunction(key);
    Node *tmpNode = hashTable[hashInx].head;

    if (tmpNode == NULL){
        printf("\nno key found");
        return;
    }

    while (tmpNode != NULL){
        // key를 찾음
        if (tmpNode->key == key){
            printf("key found key = [%d] value = [%d]", tmpNode->key, tmpNode->value);
            return;
        }
        tmpNode = tmpNode->next;
    }

    printf("\nno key found");
    return;
}


void display(){
    Node *horseNode;

    for (int i = 0; i < SIZE; i++){
        horseNode = hashTable[i].head;
        printf("Bucket[%d]", i);

        while(horseNode != NULL){
            printf("(key : %d, val : %d) -> ", horseNode->key, horseNode->value);
            horseNode = horseNode->next;
        }
        printf("\n");
    }
    printf("\n---------- end of display ----------\n");

    return;
}