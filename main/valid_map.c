#include "../_includes/cub3d.h"

int	check_first_last_line(char *first_line)
{
	int	i;

	i = 0;
	while (first_line[i])
	{
		if (first_line[i] != '1' && (first_line[i] != 32
				|| first_line[i] != '\t'))
		{
			printf(RED "Map should be entouring by 1\n" RESET);
			return (1);
		}
		i++;
	}
	return (0);
}

int	any_empty_line(char **map)
{
	int		i;
	char	*trim;

	i = 0;
	while (map[i])
	{
		trim = ft_strtrim(map[i], " \t\n");
		if (trim[0] == '\0')
			return (free(trim), 1);
		free(trim);
		i++;
	}
	return (0);
}

int	decalage_line(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N')
			{
				if (map[i][j + 1] && !(map[i][j + 1] == '0' || map[i][j
						+ 1] == '1' || map[i][j + 1] == 'N'))
					return (1);
				if (j > 0 && !(map[i][j - 1] == '0' || map[i][j - 1] == '1'
						|| map[i][j - 1] == 'N'))
					return (1);
				if (trim_decale(map, i, j))
					return (1);
			}
		}
	}
	return (0);
}

int	last_catch_error(char **map, t_cub *cub)
{
	if (cub->flag_p != 1)
		return (1);
	resize_map(map, cub);
	if (any_empty_line(cub->caste_info->map))
		return (1);
	if (decalage_line(cub->caste_info->map))
		return (1);
	return (0);
}

int	valid_character_map(char *map, int *flag, t_cub *cub)
{
	char	*trim_line;
	int		j;

	trim_line = ft_strtrim(map, " \t\n");
	if (!*flag && check_first_last_line(trim_line) != 0)
		return (free(trim_line), (1));
	*flag = 1;
	j = 0;
	while (trim_line[j])
	{
		if (trim_line[0] != '1' || trim_line[ft_strlen(trim_line) - 1] != '1')
			return (free(trim_line), (1));
		if (trim_line[j] != '1' && trim_line[j] != '0' && (trim_line[j] != 32
				|| trim_line[j] != '\t')
			&& !symbolic_character(trim_line[j]))
			return (free(trim_line), (1));
		if (symbolic_character(trim_line[j]))
			cub->flag_p++;
		j++;
	}
	free(trim_line);
	trim_line = NULL;
	return (0);
}
