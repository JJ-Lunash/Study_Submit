#include <stdio.h>

int main(){
    char dest[] = "hello";
    char source[] = "world";

    ft_strcat(dest, source);
    printf("%s", dest);
    return 0;
}