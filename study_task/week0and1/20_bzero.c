#include <stdlib.h>

void *ft_bzero(void *dest, size_t len)
{
    int i = 0;
    unsigned char *temp;

    temp = (unsigned char *)dest;
    while (i < len)
    {
        dest = 0;
        dest++;
        i++;
    }
    return (temp);
}

memset(dest, 0, sizeof(dest));

// memset 0, 1에 해당하는 걸로 초기화가 가능하다..?
// 그 이상 값이 들어가면 이상하게 나온다.

/* < 함수 인자에 대한 설명>
   dest: 채우고자 하는 메모리의 시작 포인터
   len: 메모리에 채우고자 하는 값,
        int형 이지만 내부에서는 unsigned char로 변환되어서 저장된다.*/