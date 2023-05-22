#include "Stack.h"

Stack *createStack(size_t size)
{
    Stack *newStk;

    newStk = (Stack *)malloc(sizeof(Stack));
    newStk->storage = (FixedArray *)malloc(sizeof(FixedArray));
    newStk->storage->Storage = (int *)malloc(sizeof(int) * size);
    memset(newStk, 0, size);
    newStk->storage->Size = 0;
    newStk->storage->Capacity = size;

    return (newStk);
}


Stack *copyStack(Stack *stack)
{
    if (stack == NULL)
        return 0;

    Stack *copyStk = (Stack *)malloc(sizeof(stack));
    copyStk->storage = (FixedArray *)malloc(sizeof(stack->storage));
    copyStk->storage->Storage = (int *)malloc(sizeof(int) * stack->storage->Size);
    copyStk->storage->Size = stack->storage->Size;
    copyStk->storage->Capacity = stack->storage->Capacity;

    return (copyStk);
}


size_t size(Stack *stack)
{
    if (stack == NULL)
        return 0;

    return (stack->storage->Size);
}


size_t capacity(Stack *stack)
{
    if (stack == NULL)
        return 0;

    size_t Capacity = stack->storage->Capacity;
    return (Capacity);
}


bool isEmpty(Stack *stack)
{
    if (stack == NULL)
        return (false);

    if (stack->storage->Size == 0)
        return (true);

    return (false);
}


bool isFull(Stack *stack)
{
    if (stack == NULL)
        return (false);

    if (stack->storage->Size == capacity(stack))
        return (true);

    return (false);
}


bool push(Stack *stack, int value)
{
    if (stack == NULL || stack->storage->Size == capacity(stack))
        return (false);

    stack->storage->Storage[stack->storage->Size] = value;
    stack->storage->Size++;

    return (true);
}


int pop(Stack *stack)
{
    if (stack == NULL || stack->storage->Size == 0)
        return 0;

    int data = 0;

    data = stack->storage->Storage[stack->storage->Size - 1];
    stack->storage->Storage[stack->storage->Size - 1] = 0;
    stack->storage->Size--;

    return (data);
}


int peek(Stack *stack)
{
    if (stack == NULL || stack->storage->Size == 0)
        return 0;

    int data = 0;

    data = stack->storage->Storage[stack->storage->Size - 1];

    return (data);
}


void clearStack(Stack *stack)
{
    if (stack == NULL)
        return;

    free(stack->storage->Storage);
    stack->storage->Size = 0;
}


void destroyStack(Stack *stack)
{
    if (stack == NULL)
        return;

    if (stack->storage->Size != 0)
        clearStack(stack);
    free(stack);
}