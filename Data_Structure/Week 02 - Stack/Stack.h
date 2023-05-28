#ifndef __STACK__
#define __STACK__

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct _fixedArray {
    int *Storage;
    size_t Size;
    size_t Capacity; // 추가
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
int pop(Stack *stack); // 반환 void->int로 수정
int peek(Stack *stack);

void clearStack(Stack *stack);
void destroyStack(Stack *stack);

#endif // __STACK__