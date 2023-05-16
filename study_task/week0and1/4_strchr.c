char *ft_strchr(char *str, char c)
{
    while (*str)
    {
        if (*str == c)
            return (str);
        str++;
    }
    return 0;
}

/* strchr함수와 strrchr함수의 비교
    : 해당 글자를 찾은 경우,
    strchr은 맨 앞 포인터 반환,
    strrchr은 맨 뒤 포인터 반환 */

/* Q1. 첫 번째 인자에 const를 붙여아하는 이유는?
    (처음 코드를 작성할 때 const를 붙이지 않음) */

/* Q2. 두 번째 인자에 char이 아닌 int가 어가야하는 이유는?
       그리고 char로 하면 안되나?
    (처음 코드를 작성할 때 char로 작성) */

// char는 0~255까지의 정수를 저장할 수 있음
// 그 중에서 ascii코드는 0~127까지의 정수를 저장할 수 있음
// char로도 위의 로직은 가능함. int로도 가능함.