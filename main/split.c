#include "../_includes/cub3d.h"

int	check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	c_word(char *str, char *charset)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
			w++;
		while (str[i] != '\0' && !check_sep(str[i], charset))
			i++;
	}
	return (w);
}

int	c_char(char *str, char *charset)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i] != '\0' && !check_sep(str[i], charset))
	{
		c++;
		i++;
	}
	return (c);
}

char	*word(char *str, char *charset)
{
	char	*w;
	int		i;

	i = 0;
	w = malloc(c_char(str, charset) + 1);
	while (str[i] != '\0' && !check_sep(str[i], charset))
	{
		w[i] = str[i];
		i++;
	}
	w[i] = '\0';
	return (w);
}

char	**exec_split(char *str, char *charset)
{
	char		**split;
	int			i;
	int			w;

	w = 0;
	i = 0;
	split = malloc(sizeof(char **) * (c_word(str, charset) + 1));
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			split[w] = word(str + i, charset);
			w++;
		}
		while (str[i] != '\0' && !check_sep(str[i], charset))
			i++;
	}
	split[w] = NULL;
	return (split);
}
