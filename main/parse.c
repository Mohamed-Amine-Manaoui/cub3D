#include "../_includes/cub3d.h"

int	check_first_line(char *first_line)
{
	int	i;

	i = 0;
	while (first_line[i])
	{
		if (first_line[i] != '1')
		{
			printf(RED "Map should be entouring by 1\n" RESET);
			return (1);
		}
		i++;
	}
	return (0);
}

int	valid_character_map(char *map, int *flag)
{
	char	*trim_line;
	int		j;

	trim_line = ft_strtrim(map, " \t");
	if (!*flag && check_first_line(trim_line) != 0)
		return (1);
	*flag = 1;
	j = 0;
	while (trim_line[j])
	{
		if (trim_line[0] != '1' || trim_line[ft_strlen(trim_line) - 1] != '1')
			return (free(trim_line), (1));
		if (trim_line[j] != '1' && trim_line[j] != '0')
			return (free(trim_line), (1));
		j++;
	}
	free(trim_line);
	trim_line = NULL;
	return (0);
}
int	is_valid_map(char **map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '\0')
		{
			// valid character map
			if (valid_character_map(map[i], &flag))
				return (1);
		}
		i++;
	}
	return (0);
}

void	read_file(t_cub *cub, t_raycaste *caste)
{
	cub->line = get_next_line(cub->fd);
	if (!cub->line)
		(ft_free(cub), exit(printf(RED "Empty file\n" RESET)));
	while (cub->line)
	{
		skip_whitespaces(cub, cub->line);
		if (cub->redirect_symbol && cub->redirect_file)
			check_current_line(cub, caste);
		else if (cub->redirect_symbol && !cub->redirect_file)
			(printf(RED " %s :xpm file not found !!\n" RESET,
					cub->redirect_symbol), ft_free(cub), free(cub->line),
				ft_free_symbol(cub), exit(1));
		// read  map
		if (cub->count == 6)
		{
			free(cub->line);
			cub->line = get_next_line(cub->fd);
			if (!cub->line)
				exit(printf("NULL_line\n"));
			while (cub->line)
			{
				caste->trimmed_line = ft_strtrim(cub->line, "\n");
				caste->map = ft_realloc(caste->map, sizeof(char *) * caste->row,
						sizeof(char *) * (caste->row + 2));
				caste->map[caste->row] = ft_strdup(caste->trimmed_line);
				free(caste->trimmed_line);
				caste->map[caste->row + 1] = NULL;
				caste->row++;
				free(cub->line);
				cub->line = get_next_line(cub->fd);
			}
			if (is_valid_map(caste->map))
			{
				(ft_free(cub), free_split(caste->map));
				free_caste_struct(caste);
				printf(RED "Invalid Map\n" RESET), exit(1);
			}
			break ;
		}
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
}
