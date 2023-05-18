#ifndef __FIXEDARRAY__
#define __FIXEDARRAY__

#include <stdbool.h>
#include <stddef.h>

typedef struct _vector {
    int *data;
    size_t size;
    size_t capacity;
}   Vector;

Vector *createVector(size_t capacity);
Vector *copyVector(Vector *vector);

bool pushBack(Vector *vector, int value);
bool popBack(Vector *vector);
bool insert(Vector *vector, size_t index, int value);
bool erase(Vector *vector, size_t index);
int get(Vector *vector, size_t index);

size_t getSize(Vector *vector);
size_t getCapacity(Vector *vector);

bool isEmpty(Vector *vector);
bool isFull(Vector *vector);

void swapVector(Vector *vector1, Vector *vector2);

void clearVector(Vector *vector);
void destroyVector(Vector *vector);

#endif // __FIXEDARRAY__