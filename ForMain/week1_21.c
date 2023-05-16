#include <stdio.h>
int main(){
    char *s1 = "abcd";
    char *s2 = "abd";
    int rst;

    rst = ft_strequ(s1, s2);
    printf("%d\n", rst);
    return 0;
}