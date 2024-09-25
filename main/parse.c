#include "../_includes/cub3d.h"

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
	cub->redirection_symbol = ft_strtrim(tmp, " \t\n");
	free(tmp);
	tmp = NULL;
	if (cub->redirection_symbol[0] == '\0')
	{
		free(cub->redirection_symbol);
		cub->redirection_symbol = NULL;
	}
	j--;
	k = 0;
	j = j + i + 1;
	while (str[k + j])
		k++;
	tmp = ft_substr(str, j, k);
	cub->redirection_file = ft_strtrim(tmp, "\t \n");
	if (cub->redirection_file[0] == '\0')
	{
		free(cub->redirection_file);
		cub->redirection_file = NULL;
	}
	free(tmp);
}

void	check_current_line(t_cub *cub)
{
	if (ft_strcmp(cub->redirection_symbol, "NO") == 0)
	{
		xpm_extension(cub->redirection_file, cub);
	}
	else if (ft_strcmp(cub->redirection_symbol, "SO") == 0)
	{
		xpm_extension(cub->redirection_file, cub);
	}
	else if (ft_strcmp(cub->redirection_symbol, "WE") == 0)
	{
		xpm_extension(cub->redirection_file, cub);
	}
	else if (ft_strcmp(cub->redirection_symbol, "EA") == 0)
	{
		xpm_extension(cub->redirection_file, cub);
	}
	else if (ft_strcmp(cub->redirection_symbol, "F") == 0)
	{
		//floor
	}
	else if (ft_strcmp(cub->redirection_symbol, "C") == 0)
	{
		//sky
	}
	cub->count++;
}

void	read_file(t_cub *cub)
{
	cub->line = get_next_line(cub->fd);
	while (cub->line)
	{
		skip_whitespaces(cub, cub->line);
		if (cub->redirection_symbol && cub->redirection_file)
			check_current_line(cub);
		else if (cub->redirection_symbol && !cub->redirection_file)
			(printf(RED " %s :xpm file not found !!\n" RESET,
					cub->redirection_symbol), ft_free(cub), free(cub->line),
				exit(1));
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
}
