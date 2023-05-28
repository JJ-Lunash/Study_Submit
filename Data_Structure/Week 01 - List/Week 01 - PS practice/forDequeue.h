#ifndef __DEQUEUE__
#define __DEQUEUE__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _dequeue {
    int *dataList;
    int front, rear;
    int maxSize;
} Dequeue;

Dequeue *createAndInitDequeue(int size); // 덱 생성 및 초기화

bool is_empty(Dequeue *dq); // 덱이 공백 상태인지 검사
bool is_full(Dequeue *dq); // 덱이 포화 상태인지 검사

void addFront(Dequeue *dq, int e); // 덱의 front에 요소 추가
void addRear(Dequeue *dq, int e); // 덱의 rear에 요소 추가

int delFront(Dequeue *dq); // 덱의 front에 있는 요소를 반환한 뒤 삭제
int delRear(Dequeue *dq); // 덱의 rear에 있는 요소를 반환한 뒤 삭제

int getFront(Dequeue *dq);//덱의 front에 있는 요소 반환만 하고 삭제는 X
int getRear(Dequeue *dq);//덱의 rear에 있는 요소 반환만 하고 삭제는 X

/*
덱의 주의할 점
    - 데이터 삽입 연산 시 front는 감소, rear은 증가
    - 데이터 삭제 연산 시 front는 증가, rear은 감소
*/

#endif // __DEQUEUE__