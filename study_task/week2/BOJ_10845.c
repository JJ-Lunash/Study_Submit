// [ 큐 (queue) ]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_Q_SIZE 10000

typedef int element;
int queue[MAX_Q_SIZE];
int start = 0, end = 0; cnt = 0;

void push(int x)
{
    queue[end] = x;
    end++;
    cnt++;
}

void pop()
{
    if (cnt != 0)
    {
        printf("%d\n", queue[start]);
        start++;
        cnt--;
    }
    else
        printf("-1\n");
}

void size()
{
    printf("%d\n", cnt);
}

void empty()
{
    if (cnt == 0)
        printf("1\n");
    else
        printf("0\n");
}

void front()
{
    if (cnt != 0)
        printf("%d\n", queue[start]);
    else
        printf("-1\n");
}

void back()
{
    if (cnt != 0)
        printf("%d\n", queue[end]);
    else
        printf("-1\n");
}

int main()
{
    int n = 0, i = 0;
    char command[6];
    int push_x;
    scanf("%d", &n);
    while (i < n)
    {
        scanf("%s", command);
        if (!strcmp(command, "push"))
        {
            scanf("%d", &push_x);
            push(push_x);
        }
        else if (!strcmp(command, "pop"))
            pop();
        else if (!strcmp(command, "pop"))
            size();
        else if (!strcmp(command, "pop"))
            empty();
        else if (!strcmp(command, "pop"))
            front();
        else if (!strcmp(command, "pop"))
            back();
        i++;
    }
    return (0);
}