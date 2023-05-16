int	ft_isprint(char *str)
{
	int	i;

	if (*str == '\0')
		return (1);
	i = 0;
	while (*(str + i))
	{
		if (str[i] >= 32 && str[i] <= 126)
			i++;
		else
			return (0);
	}
	return (1);
}