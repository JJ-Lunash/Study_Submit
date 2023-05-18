#include "Vector.h"

template <typename T> // T는 Vector가 담을 데이터 타입
class Vector
{
    T* _data; // Vector가 담을 데이터를 가리키는 포인터
    size_t _size; // Vector가 담고 있는 데이터의 개수
    size_t _capacity; // Vector가 기존에 할당한, 담을 수 있는 데이터의 개수
};

typedef struct _vector {
    int *data;
    size_t size;
    size_t capacity;
}   Vector;

Vector *createVector(size_t capacity)
{
    Vector *new_arr;

    if (!new_arr->capacity) return (NULL); // 예외 처리

    memset(new_arr, 0, sizeof(int) * size); // 초기화
    new_arr->size = size;

    return (new_arr);
}


Vector *copyVector(Vector *vector);
{

}


bool pushBack(Vector *vector, int value);
{

}


bool popBack(Vector *vector);
{

}


bool insert(Vector *vector, size_t index, int value);
{

}


bool erase(Vector *vector, size_t index);
{

}


int get(Vector *vector, size_t index);
{

}


size_t getSize(Vector *vector);
{

}


size_t getCapacity(Vector *vector);
{

}


bool isEmpty(Vector *vector);
{

}


bool isFull(Vector *vector);
{

}


void swapVector(Vector *vector1, Vector *vector2);
{

}


void clearVector(Vector *vector);
{

}


void destroyVector(Vector *vector);
{

}

