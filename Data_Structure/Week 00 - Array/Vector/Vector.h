#ifndef __FIXEDARRAY__
#define __FIXEDARRAY__

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h> // malloc을 위해 추가
#include <string.h> // memset을 위해 추가

typedef struct _vector {
    int *data; // Vector가 담을 데이터를 가리키는 포인터
    size_t size; // Vector가 담고 있는 데이터의 개수
    size_t capacity; // Vector가 기존에 할당한, 담을 수 있는 데이터의 개수
}   Vector;

void error(char *errorMessage); // 새로 추가
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

/*
정리할 것들
    - 구조체복사 시 주의할 것 / 얕은 & 깊은 복사
    -
*/