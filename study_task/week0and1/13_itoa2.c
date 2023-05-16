#include "libft.h"
#include <stdio.h>

// 숫자를 문자열로 변환하여 반환해주는 함수
// 0에 대한 예외 처리 필요
// 숫자 길이 구하는 함수 필요

size_t ft_int_len(int n)
{
    size_t len;

    if (n == 0)
        return (1);
    len = 0;
    while (n != 0)
    {
        n/= 10;size_t ft_int_len(int n);
char *ft_itoa2(int n);
        len++;
    }
    if (len < 0)
        len++;

    return (len);
}

char *ft_itoa2(int n)
{
    long num;
    size_t len;
    char *str;

    len = ft_int_len(n);
    num = n;
    str = malloc(len * sizeof(char) + 1);

    if (!str)
        return 0;

    if (num < 0)
    {
        str[0] = '-';
        num *= -1;
    }
    if (num == 0)
        str[0] = '0';

    str[len] = '\0';
    len--;
    while (num != 0)
    {
        str[len] = num % 10 + '0';
        num /= 10;
        len--;
    }
    return (str);
}

int main(){
    int num1 = 12345;
    int num2 = 0;
    int num3 = -12345;

    ft_itoa2(num1);
    ft_itoa2(num2);
    ft_itoa3(num3);

}