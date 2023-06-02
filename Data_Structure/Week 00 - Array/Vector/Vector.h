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
벡터란? 길이가 변하는 집합, 방향, 자료구조
어떻게 변하나? cpp Vector의 경우, 기존 capacity만큼 다 차고나면 *2 만큼 늘리기 (resize 행위)
*/