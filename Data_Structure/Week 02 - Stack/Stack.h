#ifndef __STACK__
#define __STACK__

#include <stdbool.h>
#include <stddef.h>

typedef struct _fixedArray {
    int *Storage;
    size_t Size;
}       FixedArray;

typedef struct _Stack {
  FixedArray *storage;
} Stack;

Stack *createStack(size_t size);
Stack *copyStack(Stack *stack);

size_t size(Stack *stack);
size_t capacity(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);

bool push(Stack *stack, int value);
bool pop(Stack *stack);
int peek(Stack *stack);

void clearStack(Stack *stack);
void destroyStack(Stack *stack);

#endif // __STACK__