#include <stdlib.h>

int	is_c(char str_i, char c)
{
	if (str_i == c)
		return (1);
	return (-1);
}

int	words_num(char *str, char c)
{
	int	count_words;
	int	i;

	count_words = 0;
	i = 0;
	while (str[i])
	{
		while (is_c(str[i], c) == 1 && str[i] != '\0')
			i++;
		if ((is_c(str[i], c) == -1) && str[i] != '\0')
			count_words++;
		while (is_c(str[i], c) == -1 && str[i] != '\0')
			i++;
	}
	return (count_words);
}

void split_words(char **arr, char *str, char c)
{
	int	i;
	int	j;
	int	word;
	int	idx;

	word = 0;
	i = 0;
	if (words_num(str, c) == 0)
		return ;
	while (word < words_num(str, c))
	{
		while (is_c(str[i], c) == 1)
			i++;
		j = i;
		while (is_c(str[j], c) == -1 && str[j] != '\0')
			j++;
		arr[word] = malloc(sizeof(char) * (j - i + 1));
		idx = 0;
		while (i < j)
			arr[word][idx++] = str[i++];
		arr[word][idx] = '\0';
		word++;
	}
}

char **ft_split(char const *s, char c)
{
	char	**result_arr;
	int		words;

	words = words_num(s, c);
	if (words == 0)
        return (NULL);
	result_arr = (char **)malloc(sizeof(char *) * (words + 1));
	result_arr[words] = 0; //세그폴트날수잇는거가능성??
	split_words(result_arr, s, c);
	return (result_arr);
}
