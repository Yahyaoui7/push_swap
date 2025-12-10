#include <stdio.h>
#include <stdlib.h>

static char	**free_word(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (NULL);
}

static int	count_word(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c && ((i == 0) || str[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

static char	*got(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_split_wods(const char *s, char **ptr, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		tmp = got(s, c);
		if (!tmp)
			return (free_word(ptr, i));
		ptr[i++] = tmp;
		while (*s && *s != c)
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	ptr = malloc((count + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	if (count == 0)
	{
		ptr[0] = NULL;
		return (ptr);
	}
	return (ft_split_wods(s, ptr, c));
}
int	main(void)
{
	char	**num;
	int		i;

	num = ft_split("    nabil yahyaoui       idrissi   ", ' ');
	i = 0;
	while (num[i])
	{
		printf("%s\n", num[i]);
		i++;
	}
}
