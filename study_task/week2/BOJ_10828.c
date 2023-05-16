// [ 스 택 ]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10000
typedef int element;
int stack[MAX_STACK_SIZE];
int high = -1;

int empty()
{
    if (high == -1)
        return 1;
    return 0;
}

void push(element x)
{
    if (high >= MAX_STACK_SIZE - 1)
    {
        fprintf(stderr, "stack saturation error");
        return;
    }
    else
        high++;
        stack[high] = x;
}

int pop()
{
    int return_top;
    if (empty(stack) == 1)
        return (-1);
    else
        return_top = stack[high];
        high--;
    return (return_top);
}

int size()
{
    if (empty(stack) == 1)
        return 0;
    return (high + 1);
}

int top()
{
    if (empty(stack) == 1)
        return (-1);
    return (stack[high]);
}

int main()
{
    int n = 0;
    element push_x = 0;
    char command[6];
    int i = 0;

    scanf("%d", n);
    while (i < n)
    {
        scanf("%s", &command);
        if (!strcmp(command, "push"))
        {
            scanf("%d", &push_x);
            push(push_x);
        }
        else if (strcmp(command, "empty") == 0)
            printf("%d\n", empty());
        else if (!strcmp(command, "pop"))
            printf("%d\n", pop());
        else if (strcmp(command, "size") == 0)
            printf("%d\n", size());
        else if (strcmp(command, "top") == 0)
            printf("%d\n", top());
        i++;
    }
    return (0);
}