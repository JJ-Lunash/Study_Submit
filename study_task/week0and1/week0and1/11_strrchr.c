char *ft_strrchr(char *str, char c)
{
    char *temp;

    while (*str)
    {
        if (*str == c)
            temp = str;
        str++;
    }
    return *temp != '\0' ? temp : 0;
}

/* 내 함수를 구현한 후 인터넷 검색을 해보니,
    포인터를 끝까지 올린 뒤 맨 뒤에서 다 시 역순으로 돌아가며
    해당 문자를 만나면 포인터를 반환하는 방식으로 구현되어있었다.
    나와 다른 방식.*/