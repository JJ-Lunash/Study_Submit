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