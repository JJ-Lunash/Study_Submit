char *ft_strcat(char *dest, char *source)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (source[j])
    {
        dest[i] = source[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}