#include "FixedArray.h"

FixedArray *createFixedArray(size_t size)
{
    FixedArray *new_arr; // 구조체 포인터 변수 선언

    new_arr->storage = malloc(sizeof(int) * size); // 메모리 할당
    if (!new_arr->storage) return (NULL); // 예외 처리

    memset(new_arr, 0, sizeof(int) * size); // 초기화
    new_arr->size = size;

    return (new_arr);
}


FixedArray *copyFixedArray(FixedArray *fixedArray)
{
    FixedArray *copy_arr;
    int i = 0;

    if (!fixedArray->storage) return 0;
    copy_arr->storage = malloc(sizeof(fixedArray->size));
    while (copy_arr->storage[i])
    {
        copy_arr->storage[i] = fixedArray->storage[i];
        i++;
    }
    copy_arr->size = fixedArray->size;

    return (copy_arr);
}


bool setFixedArray(FixedArray *fixedArray, int index, int value)
{
    int i = 0;

    if (!fixedArray->storage) return 0; // 예외처리 1 : fixedArray->storage == NULL인 경우
    if (index < 0 || index > fixedArray->size) return 0; // 예외처리 2 : index가 유효하지 않은 경우

    while (i < fixedArray->size)
    {
        if (value < -2147483648 || value > 2147483647) return 0; // 예외처리 3 : value가 유효하지 않은 경우
        fixedArray->storage[index++] = value;
        i++;
    }

    return (1); // 잘 모르겠다
}


int getFixedArray(FixedArray *fixedArray, int index)
{
    int data = 0;
    int i = 0;

    if (!fixedArray->storage) return 0; // 예외처리 1 : fixedArray == NULL인 경우
    if (index < 0 || index > fixedArray->size) // 예외처리 2 : index가 유효하지 않은 경우
    {
        write(1, "Error: Out or range", 19);
        return 0;
    }

    data = fixedArray->storage[index];

    return (data);
}


bool deleteFixedArray(FixedArray *fixedArray, int index)
{
    FixedArray *tmpArray = 0;
    int i = 0;
    if (!fixedArray->storage) return 0; // 예외처리 1 : fixedArray == NULL인 경우
    if (index < 0 || index > fixedArray->size) return 0; // 예외처리 2 : index가 유효하지 않은 경우

    tmpArray->size = fixedArray->size - 1;
    tmpArray->storage = malloc(sizeof(int) * tmpArray->size);

    while (i < index - 1)
    {
        tmpArray->storage[i] = fixedArray->storage[i];
        i++;
    }
    while(fixedArray->storage[index])
    {
        tmpArray->storage[index] = fixedArray->storage[index + 1];
        index++;
    }

    fixedArray = tmpArray; // 다른 구조체 만들었다가 구조체 = 구조체 식으로 통째 복사 가능

    return (true); /////////////??
}


size_t getSizeFixedArray(FixedArray *fixedArray) // 아직미완성~~~~~~~~~~~
{
    size_t len = 0;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~밑에 리턴값들 어떻게처리해야할지모르겟어~
    if (!fixedArray->storage) return 0;

    if (fixedArray->size == 0) return 0;
    len = fixedArray->size;

    return (len);
}

bool isEmptyFixedArray(FixedArray *fixedArray)
{
    if(!fixedArray->storage) eturn (0);

    while(*(fixedArray->storage))
    {
        if (*(fixedArray->storage) != 0)
            return (false);
        fixedArray->storage++;
    }

        return (true);
}


bool isFullFixedArray(FixedArray *fixedArray) // ??
{

}


void clearFixedArray(FixedArray *fixedArray)
{
    int i = 0;

    if(!fixedArray->storage) eturn (0);

    memset(&(fixedArray->storage[i]), 0, sizeof(fixedArray->size));
}


void deletesFixedArray(FixedArray *fixedArray)
{
    memset(fixedArray, 0, sizeof(fixedArray));
    free(fixedArray);
}