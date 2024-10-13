#include "../_includes/cub3d.h"

int	trim_decale(char **map, int i, int j)
{
	char	*trim;

	trim = ft_strtrim(map[i + 1], " \t\n");
	if (i > 0 && ft_strlen(map[i + 1]) <= (size_t)j)
	{
		return (free(trim), 1);
	}
	free(trim);
	trim = ft_strtrim(map[i - 1], " \t\n");
	if (i > 0 && ft_strlen(trim) <= (size_t)j)
	{
		free(trim);
		return (1);
	}
	free(trim);
	return (0);
}

void	process_header_lines(t_cub *cub, t_raycaste *caste)
{
	skip_whitespaces(cub, cub->line);
	if (cub->redirect_symbol && cub->redirect_file)
		check_current_line(cub, caste);
	else if (cub->redirect_symbol && !cub->redirect_file)
	{
		printf(RED " %s :xpm file not found !!\n" RESET, cub->redirect_symbol);
		ft_free(cub);
		free(cub->line);
		ft_free_symbol(cub);
		exit(1);
	}
}

void	read_map(t_cub *cub, t_raycaste *caste)
{
	while (cub->line)
	{
		caste->map = ft_realloc(caste->map, sizeof(char *) * caste->row,
				sizeof(char *) * (caste->row + 2));
		caste->trimmed_line = ft_strtrim(cub->line, "\n");
		caste->map[caste->row] = ft_strdup(caste->trimmed_line);
		free(caste->trimmed_line);
		caste->map[caste->row + 1] = NULL;
		caste->row++;
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
}

void	validate_map(char **clone_map, t_cub *cub, t_raycaste *caste)
{
	if (is_valid_map(clone_map, cub))
	{
		ft_free(cub);
		free_split(clone_map);
		free_split(caste->map);
		free_caste_struct(caste);
		printf(RED "Invalid Map\n" RESET);
		exit(1);
	}
}

void	check_map_presence(t_cub *cub, t_raycaste *caste)
{
	free(cub->line);
	cub->line = get_next_line(cub->fd);
	if (!cub->line)
	{
		ft_free(cub);
		free_caste_struct(caste);
		exit(printf(RED "Map not found\n" RESET));
	}
}
