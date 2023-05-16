/* 흐름은 어느정도 맞는 것 같은데, 간단히 테스트 돌려보려했는데 s1,s2가 const형이라 ft_strlen함수에서 거절한다고하며 실행자체가 안되는 문제가 있었습니다.
const에 대해 찾아보고 그 이유를 고민해봤으나 const는 붙는 위치에 따라 그 값 또는 주소를 못바꾸게 고정시켜주는 역할이고, 제 ft_strlen에서는
그저 길이를 셀 뿐 값을 바꾸지도않고 또 i를 사용해서 주소를 직접 올려주는 방식을 사용한 것도 아닌데 왜 안된다는건지 잘 모르겠습니다!
고민해보고 찾아봤으나 어떻게 고쳐야하는건지 잘 모르겠어서 돌아가지 않는 틀린 코드 그대로 올립니다..ㅎㅎ */


#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *rst_arr;
    int s1_len = ft_strlen(s1);
    int s2_len = ft_strlen(s2);
    int i = 0;
    int j = 0;

    rst_arr = malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (!rst_arr)
        return 0;
    while (rst_arr[i])
    {
        while (s1[j])
        {
            rst_arr[i] = s1[j];
            i++;
            j++;
        }
        j = 0;
        while (s2[j])
        {
            rst_arr[i] = s2[j];
            i++;
            j++;
        }
        rst_arr[i] = '\0';
        return (rst_arr);
    }

#include <stdio.h>

int main()
{
    char *s1 = "abcd";
    char *s2 = "efg";
    char *rst_arr;

    rst_arr = ft_strjoin(s1, s2);
    printf("&s", rst_arr);
    return 0;
}