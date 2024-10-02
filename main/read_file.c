#include "../_includes/cub3d.h"


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

void	process_file_lines(t_cub *cub, t_raycaste *caste)
{
	char	**clone_map;

	while (cub->line)
	{
		process_header_lines(cub, caste);
		if (cub->count == 6)
		{
			check_map_presence(cub, caste);
			// Read and store the map
			read_map(cub, caste);
			// Validate the map
			clone_map = duplicate_string(caste->map);
			validate_map(clone_map, cub, caste);
			free_split(clone_map);
			break ;
		}
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
	if (!cub->line)
	{
		ft_free(cub);
		exit(printf(RED "Empty file\n" RESET));
	}
}
