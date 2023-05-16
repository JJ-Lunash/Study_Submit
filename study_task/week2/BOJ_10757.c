// [ 큰  수  A  와  B  더 하 기]
/*
스터디 때 질문할 것: 최종 제출한 코드가 왜 맞는지는 알겠으나,
ft_add함수 큰 while문에서 <rst_len으로 했을 때
왜 프린트값에서 다른부분은 다 맞게나오고 1만 맨뒤로 가있는가?
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void ft_rvs(char *str, int len)
{
    int i = 0;
    char temp;
    while (i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        i++;
    }
}

void ft_add(char *str1, char *str2, char *rst, int rst_len)
{
    int carry = 0;
    int i = 0, sum = 0;
    while (i < rst_len - 1)
    {
        sum = str1[i] + str2[i] - '0' * 2  + carry;
        while (sum < 0) // 이 두줄 표현방식 잘 기억해두기(기존의 나는 if문으로 경우 여러 개 나누는 생각밖에 못함)
            sum += '0';
        if (sum > 9)
            carry = 1;
        else 
            carry = 0;
        rst[i] = sum % 10 + '0';
        i++;
    }
    if (carry == 1)
        rst[i] = '1';
    ft_rvs(rst, rst_len);
}

int main()
{
    char str1[100002] = {0}, str2[100002] = {0};
    char rst[100003];
    int len1, len2, rst_len; 

    scanf("%s %s", str1, str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    rst_len = (len1 >= len2 ? len1 + 1 : len2 + 1); //삼항연산자를 처음으로 자연스럽게 떠올리고 사용하기 시작한 날!

    ft_rvs(str1, len1);
    ft_rvs(str2, len2);
    ft_add(str1, str2, rst, rst_len); //질문: ft_add의 반환형을 char *로 하여 받아오는건 왜안되나? (rst가 변경할 수 없다는데 정확히모르겠음)

    printf("%s", rst);

    return 0;
}

/*
- scanf에서 double은 lf 사용
- 실수를 printf했을 때 기본적으로 소수점 이하 6자리까지 나옴
- n개만큼의 소수점 출력하고 싶다면 %nf 사용!
- 소수점 아예 출력하고 싶지 않을 때, %0f말고 %.f도 가능
- ??? 최대 정밀도, 유효 정밀도
*/

/*
이 문제 풀이 방법은 위 주석과 상관없다는 것을 깨닫게 됨.
문자열 더하기 규칙 만들자! 
*/