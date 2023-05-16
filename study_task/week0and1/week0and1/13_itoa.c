#include <stdlib.h>

long long ft_abs(int num) // 오버플로우 방지를 위하여 long long 사용
{
    long long abs_num;
    abs_num = num;
    if (abs_num < 0)
        return (abs_num * -1);
    return (abs_num);
}

int ft_intlen(int num)
{
    int len;
    long long abs_num;

    len = 0;
    abs_num = ft_abs(num);
    while (abs_num)
    {
        len++;
        abs_num /= 10;
    }
    return (len);
}

char *ft_itoa(int num)
{
    long long abs_num;
    int len;
    int i;
    char *str;

    abs_num = ft_abs(num);
    len = ft_intlen(num);
    if (num < 0) // 부호공간 만들어주기 위한 방법으로 이렇게 간단히 두 줄 써주는건 힌트 얻어온거임
        len++;
    str = malloc(sizeof(char) * (len + 1) + (num < 0 ? 1 : 0));
    if (!str)
        return (0);
    if (num < 0)
        str[0] = '-';
    i = 0;
    while (i <= len)
    {
        if (str[len - i] != '-')
            str[len - i] = (abs_num % 10) + '0';
        abs_num /= 10;
        i++;
    }
    str[len] = '\0';
    return (str);
}

// TODO : 수정!!!