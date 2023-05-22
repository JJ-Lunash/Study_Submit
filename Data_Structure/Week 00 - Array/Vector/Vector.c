//create하는 것부터 세그폴트 뜸 해결 안됨

#include "Vector.h"
#include <stdio.h>
#define TEST_SIZE 10

void error(char *errorMessage)
{
    fprintf(stderr, "%s\n", errorMessage);
    exit(1);
}


Vector *createVector(size_t capacity)
{
    Vector *newVec = 0;

    if (newVec->capacity == 0)
        return (NULL);

    newVec->data = (int *)malloc(sizeof(int) * capacity);
    memset(newVec, 0, capacity); // 초기화
    newVec->size = 0;
    newVec->capacity = capacity;

    return (newVec);
}


Vector *copyVector(Vector *vector)
{
    if (vector == NULL)
        return (NULL);

    Vector *copyVec = (Vector *)malloc(sizeof(Vector));
    copyVec->size = vector->size;
    copyVec->capacity = vector->capacity;
    copyVec->data = (int *)malloc(sizeof(int) * copyVec->capacity);
    size_t i = 0;

    while (i < copyVec->size)
    {
        copyVec->data[i] = vector->data[i];
        i++;
    }

    return (copyVec);
}


bool pushBack(Vector *vector, int value)
{
    if (vector == NULL)
        return (false);

    size_t i = 0;

    if (vector->size < vector->capacity)
    {
        vector->data[vector->size] = value;
    }
    else
    {
        vector->capacity *= 2;
        int *newData = (int *)malloc(sizeof(int) * vector->capacity);
        while (i < vector->size)
        {
            newData[i] = vector->data[i];
            i++;
        }
        newData[i] = value;
        vector->data = newData;
    }
    vector->size += 1;

    return (true);
}


bool popBack(Vector *vector)
{
    if (vector == NULL)
        return (false);

    vector->data[vector->size] = 0;
    vector->size -= 1;

    return (true);
}


bool insert(Vector *vector, size_t index, int value)
{
    if (vector == NULL || index > vector->capacity - 1)
        return (false);

    vector->data[index] = value;
    vector->size += 1;

    return (true);
}


bool erase(Vector *vector, size_t index)
{
    if (vector == NULL || index > vector->capacity - 1)
        return (false);

    while (index + 1 < vector->size)
    {
        vector->data[index] = vector->data[index + 1];
        index++;
    }
    vector->data[index] = 0;
    vector->size -= 1;

    return (true);
}


int get(Vector *vector, size_t index)
{
    if (vector == NULL)
        return 0;

    if (index > vector->capacity - 1)
        error("Error: Out of range");

    int value = 0;

    value = vector->data[index];

    return (value);
}


size_t getSize(Vector *vector)
{
    if (vector == NULL)
        return 0;

    return (vector->size);
}


size_t getCapacity(Vector *vector)
{
    if (vector == NULL)
        return 0;

    return (vector->capacity);
}


bool isEmpty(Vector *vector)
{
    if (vector == NULL)
        return (false);

    if (vector->size == 0)
        return (true);

    return (false);
}


bool isFull(Vector *vector)
{
    if (vector == NULL)
        return (false);

    if (vector->size == vector->capacity)
        return (true);

    return (false);
}


void swapVector(Vector *vector1, Vector *vector2)
{
    if (vector1 == NULL || vector2 == NULL)
        return;

    Vector *tmpVec;

    tmpVec = vector1;
    vector1 = vector2;
    vector2 = tmpVec;
}


void clearVector(Vector *vector)
{
    if (vector == NULL)
        return;

    free(vector->data);
    vector->size = 0;
}


void destroyVector(Vector *vector)
{
    if (vector == NULL)
        return;

    free(vector);
}

// ------------------------------------------

void printVector(Vector *arr) {
    printf("Vector: [");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", get(arr, i));
    }
    printf("]\n");
}



int main() {
    Vector *vec = createVector(TEST_SIZE);
    // Vector *vec2;

    for (int i = 0; i < TEST_SIZE; i++) {
        insert(vec, i, i * 2);
    }

    printVector(vec); // [0 2 4 6 8 10 12 14 16 18]
    // get(vec, 2); // 4
    // get(vec, 5); // 10  
    // get(vec, 20); // Error: Out of range
    // get(vec, -1); // Error: Out of range

    // getSize(vec); // 10
    // getCapacity(vec); // 10

    // pushBack(vec, 100);
    // printVector(vec); // [0 2 4 6 8 10 12 14 16 18 100]

    // getSize(vec); // 11
    // getCapacity(vec); // 20

    // for (int i = 0; i < TEST_SIZE; i++) {
    //     insert(vec2, i, i * 3);
    // }

    // printVector(vec2); // [0 3 6 9 12 15 18 21 24 27]
    // swapVector(vec, vec2);

    // printVector(vec); // [0 3 6 9 12 15 18 21 24 27]
    // printVector(vec2); // [0 2 4 6 8 10 12 14 16 18 100]

    // clearVector(vec); // clear all elements in vector->data
    // destroyVector(vec);
    // destroyVector(vec2);

    return 0;
}