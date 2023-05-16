int	ft_isdigit(char *str)
{
	int	i;

	if (*str == '\0')
		return (1);
	i = 0;
	while (*(str + i))
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}