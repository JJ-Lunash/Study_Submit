int ft_isascii(char ch)
{
    if ((ch >= 0) && (ch <= 127))
        return 1;
    return 0;
}