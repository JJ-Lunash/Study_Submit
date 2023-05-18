#ifndef __FIXEDARRAY__
#define __FIXEDARRAY__

#include <stdbool.h>
#include <stddef.h>

typedef struct _fixedArray {
    int *storage;
    size_t size;
}       FixedArray;

FixedArray *createFixedArray(size_t size);
FixedArray *copyFixedArray(FixedArray *fixedArray);

bool setFixedArray(FixedArray *fixedArray, int index, int value);
int getFixedArray(FixedArray *fixedArray, int index);
bool deleteFixedArray(FixedArray *fixedArray, int index);

size_t getSizeFixedArray(FixedArray *fixedArray);
bool isEmptyFixedArray(FixedArray *fixedArray);
bool isFullFixedArray(FixedArray *fixedArray);

void clearFixedArray(FixedArray *fixedArray);
void deletesFixedArray(FixedArray *fixedArray);

#endif // __FIXEDARRAY__