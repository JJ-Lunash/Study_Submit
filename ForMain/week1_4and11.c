#include <stdio.h>

int main(){
    char str[] = "abcdefch";
    char c = 'c';
    char *first_ptr;
    char *last_ptr;

    first_ptr = ft_strchr(str, c);
    last_ptr = ft_strrchr(str, c);
    printf("%p\n", first_ptr);
    printf("%p\n", last_ptr);
    return 0;
}