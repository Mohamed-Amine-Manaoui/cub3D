#include "../_includes/cub3d.h"

char symbolic_character(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	check_symbol_file(char **tmp, char **check)
{
	if (*check)
		free(*check);
	*check = ft_strtrim(*tmp, " \t\n");
	if (*check && *check[0] == '\0')
	{
		free(*check);
		*check = NULL;
	}
}


void	skip_whitespaces(t_cub *cub, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	j = 0;
	i = 0;
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	while (str[i + j] && str[i + j] != 32 && str[i + j] != '\t')
		j++;
	tmp = ft_substr(str, i, j);
	check_symbol_file(&tmp, &cub->redirect_symbol);
	free(tmp);
	tmp = NULL;
	j--;
	k = 0;
	j = j + i + 1;
	while (str[k + j])
		k++;
	tmp = ft_substr(str, j, k);
	check_symbol_file(&tmp, &cub->redirect_file);
	free(tmp);
}
