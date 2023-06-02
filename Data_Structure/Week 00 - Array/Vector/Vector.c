//create하는 것부터 세그폴트 뜸 해결 안됨

#include "Vector.h"
#include <stdio.h>
#define TEST_SIZE 10

void error(char *errorMessage)
{
    fprintf(stderr, "%s\n", errorMessage);
    exit(1);
}


Vector *createVector(size_t capacity)
{
    Vector *newVec = 0;
    newVec = (Vector *)malloc(sizeof(Vector));

    if (newVec->capacity == 0)
        return (NULL);

    newVec->data = (int *)malloc(sizeof(int) * capacity);
    memset(newVec, 0, capacity); // 초기화
    newVec->size = 0;
    newVec->capacity = capacity;

    return (newVec);
}


Vector *copyVector(Vector *vector)
{
    if (vector == NULL)
        return (NULL);

    // 아래 주석 부분의 경우, createVector와 로직이 겹친다 -> 해당 함수 활용해주자
    // Vector *copyVec = (Vector *)malloc(sizeof(Vector));
    // copyVec->data = (int *)malloc(sizeof(int) * copyVec->capacity);
    // copyVec->capacity = vector->capacity;
    // copyVec->size = vector->size; // 크기는 보통 맨 밑에 써주는 것이 좋음
    Vector *copyVec = createVector(vector->capacity);

    size_t i = 0;
    while (i < copyVec->size)
    {
        copyVec->data[i] = vector->data[i];
        i++;
    }

    return (copyVec);
}

// 처음에 작성했던 pushBack 함수

// bool pushBack(Vector *vector, int value)
// {
//     if (vector == NULL)
//         return (false);

//     size_t i = 0;

//     if (vector->size < vector->capacity) // 이 부분 역시 내가 만든 다른 함수 사용 가능: if (getSize(vector) == getCapacity(vector))
//         vector->data[vector->size] = value;
//     else
//     {
//         vector->capacity *= 2;
//         int *newData = (int *)malloc(sizeof(int) * vector->capacity);
//         while (i < vector->size)
//         {
//             newData[i] = vector->data[i];
//             i++;
//         }
//         newData[i] = value;
//         vector->data = newData;
//     }
//     vector->size += 1;

//     return (true);
// }

bool pushBack(Vector *vector, int value)
{
    if (vector == NULL)
        return (false);

    if (getSize(vector) == getCapacity(vector))
    {
         // 공식 문서를 보면 capacity가 0인 경우에도 vector 틀은 create 가능, capacity가 0인데 데이터 추가할 경우 capacity 1로 해서 데이터 추가해주기
        if (vector->capacity == 0)
            vector->capacity = 1;
        
        size_t i = 0;
        Vector *resizeVec = createVector(vector->capacity * 2);
        while (i < vector->size)
            pushBack(resizeVec, vector->data[i]);
        pushBack(resizeVec, value);
        resizeVec->size = vector->size + 1; // 빠뜨렸다가 나중에 추가
        Vector *tmp = vector;
        vector = resizeVec;
        destroyVector(tmp);
    }

    vector->data[vector->size] = value;

    return (true);

}


bool popBack(Vector *vector)
{
    if (vector == NULL)
        return (false);

    vector->data[vector->size] = 0;
    vector->size -= 1;

    return (true);
}

// insert, erase, get 함수 업데이트 아직 
bool insert(Vector *vector, size_t index, int value)
{
    if (vector == NULL || index > vector->capacity - 1)
        return (false);

    vector->data[index] = value;
    vector->size += 1;

    return (true);
}


bool erase(Vector *vector, size_t index)
{
    if (vector == NULL || index > vector->capacity - 1)
        return (false);

    while (index + 1 < vector->size)
    {
        vector->data[index] = vector->data[index + 1];
        index++;
    }
    vector->data[index] = 0;
    vector->size -= 1;

    return (true);
}


int get(Vector *vector, size_t index)
{
    if (vector == NULL)
        return 0;

    if (index > vector->capacity - 1)
        error("Error: Out of range");

    int value = 0;

    value = vector->data[index];

    return (value);
}


size_t getSize(Vector *vector)
{
    if (vector == NULL)
        return 0;

    return (vector->size);
}


size_t getCapacity(Vector *vector)
{
    if (vector == NULL)
        return 0;

    return (vector->capacity);
}


bool isEmpty(Vector *vector)
{
    // if (vector == NULL)
    //     return (false);

    // if (vector->size == 0)
    //     return (true);

    // return (false);

    // 위와 같이 매우 이분법적이곡 간단한 것은 삼항연산자 사용하면 한 줄로 확 줄일 수 있음
    return (vector == NULL || vector->size > 0 ? false : true);
}


bool isFull(Vector *vector)
{
    // if (vector == NULL)
    //     return (false);

    // if (vector->size == vector->capacity)
    //     return (true);

    // return (false);

    return ((vector != NULL) && (getSize(vector) == getCapacity(vector)) ? true : false);
}


void swapVector(Vector *vector1, Vector *vector2)
{
    if (vector1 == NULL || vector2 == NULL)
        return;

    Vector *tmpVec;

    tmpVec = vector1;
    vector1 = vector2;
    vector2 = tmpVec;
}


void clearVector(Vector *vector)
{
    if (vector == NULL)
        return;

    free(vector->data);
    vector->size = 0;
}


void destroyVector(Vector *vector)
{
    if (vector == NULL)
        return;

    free(vector);
}

// ------------------------------------------

void printVector(Vector *arr) {
    printf("Vector: [");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", get(arr, i));
    }
    printf("]\n");
}



int main() {
    Vector *vec = createVector(TEST_SIZE);
    // Vector *vec2;

    for (int i = 0; i < TEST_SIZE; i++) {
        insert(vec, i, i * 2);
    }

    printVector(vec); // [0 2 4 6 8 10 12 14 16 18]
    // get(vec, 2); // 4
    // get(vec, 5); // 10  
    // get(vec, 20); // Error: Out of range
    // get(vec, -1); // Error: Out of range

    // getSize(vec); // 10
    // getCapacity(vec); // 10

    // pushBack(vec, 100);
    // printVector(vec); // [0 2 4 6 8 10 12 14 16 18 100]

    // getSize(vec); // 11
    // getCapacity(vec); // 20

    // for (int i = 0; i < TEST_SIZE; i++) {
    //     insert(vec2, i, i * 3);
    // }

    // printVector(vec2); // [0 3 6 9 12 15 18 21 24 27]
    // swapVector(vec, vec2);

    // printVector(vec); // [0 3 6 9 12 15 18 21 24 27]
    // printVector(vec2); // [0 2 4 6 8 10 12 14 16 18 100]

    // clearVector(vec); // clear all elements in vector->data
    // destroyVector(vec);
    // destroyVector(vec2);

    return 0;
}