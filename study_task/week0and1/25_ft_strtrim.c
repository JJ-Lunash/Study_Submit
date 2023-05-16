#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int is_white(char c)
{
    if (c == ' ' || c == '\n' || c == '\t')
        return 1;
    return 0;
}

int new_len(char const *s)
{
    int i = 0;
    int len = 0;

    while(s[i])
    {
        if (is_white(s[i]) == 1)
            i++;
        else
        {
            len++;
            i++;
        }
    }
    return (len);
}

char *ft_strtrim(char const *s)
{
    char *rst_arr;
    int word_len = new_len(s);
    int s_len = ft_strlen(s);
    int i = 0;
    int j = 0;

    rst_arr = malloc(sizeof(char) * (word_len + 1));
    if (is_white(s[j]) == 0 || is_white(s[s_len] == 0))
        return 0;
    while(rst_arr[i])
    {
        if (is_white(s[j]) == 1)
            j++;
        else
        {
            rst_arr[i] = s[j];
            j++;
            i++;
        }
    }
    return (rst_arr);
}