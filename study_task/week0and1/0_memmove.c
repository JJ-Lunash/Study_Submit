#include <stdlib.h>

void *ft_memmove(void *dest, const void *source, size_t n)
{
    unsigned char *temp_dest;
    unsigned char *temp_source;
     //습관&느낌상 char *이건 왜 void로 안하는가?
    // 1. 일단 어떤 타입이 들어올지 장담 못함... POD type || non-POD type
    // mem 계열 함수들에선 unsigned char *로 쓰는게 일반적임.
    // char는 1byte이지만, char는 signed char이기 때문에 부호비트가 있음.
    // 묵시적형변환으로 인해 부호비트가 1이면 음수로 인식됨. (0x80 = -128)
    // 작은 타입에서 큰 타입으로의 묵시적 형변환은 부호비트를 따라서 채워짐.
    // 그래서, 복사할 때 작은 타입에서 큰 타입으로 변하는 경우 부호비트의 존재가 문제가 됨.
    // 그래서, POSIX 표준에서는 mem계열 함수들의 인자로 char *를 사용하지 않고,
    // unsigned char *를 사용함;

    size_t i = 0;
    temp_dest = (unsigned char *)dest;
    temp_source = (unsigned char *)source;
    if (dest <= source)
    {
        while (i < n)
        {
            *temp_dest = *temp_source;
            temp_dest++;
            temp_source++;
            i++;
        }
    }
    else
    {
        temp_dest += n - 1;
        temp_source += n - 1;
        while (i < n)
        {
            *temp_dest = *temp_source;
            temp_dest--;
            temp_source--;
            i++;
        }
    }
    return (dest);
}

/* memmove과 memcpy의 공통점
   : 인자와 리턴값 같음.
   : 메모리에 있는 내용을 바이트 단위로 복사하는 함수임.*/


/* memmove와 memcpy의 차이점
   : memmove는 메모리의 내용을 임시저장소에 저장한 후 복사,
     memcpy는 메모리의 내용을 직접 복사.
     따라서 memmove가 더 안정성이 좋음.
     memcpy의 경우, 자기 자신의 내용을 복사하여 덮어쓸 때,
     인접한 메모리에 의해 겹침현상(overlap)이 일어남.*/


/* 메모리가 겹칠 경우에는 cpy말고 move함수를 써야한다. */

/* pod타입이란?
    : Plain Old Data Type
    : C언어에서 기본적으로 제공하는 타입들. (ANSI-C 표준, ISO : Data type에 정의되어 있음.)
    : int, char, float, double, long, short, unsigned 등.
    : struct, union, enum, class, array 등은 pod타입이 아님.*/


// void main() {
//     unsigned char uc = 0x80;
//     printf("%d\n", uc); // 128
//     printf("%u\n", uc); // 128


//     char c = 0x80;
//     printf("%d\n", c); // -128
//     printf("%u\n", c); // 4294967168
//     // 0x80 = 1000 0000
//     // unsigned int로의 묵시적 형변환 0x80 = 1111 1111 1111 1111 1111 1111 1000 0000
//     // int로의 묵시적 형변환 0x80 = 1111 1111 1111 1111 1111 1111 1000 0000
// }