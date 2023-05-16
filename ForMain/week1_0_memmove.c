#include <stdio.h>

int main(){
    char dest[] = "12345";
    char source[] = "6789";
    ft_memmove(dest, source, 3);
    printf("%s", dest);
    return 0;
}