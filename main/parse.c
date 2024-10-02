#include "../_includes/cub3d.h"

int	is_valid_map(char **map, t_cub *cub)
{
	char	*trimed_last_l;

	int(i), (flag);
	flag = 0;
	trimed_last_l = NULL;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '\0')
		{
			if (valid_character_map(map[i], &flag, cub))
				return (1);
		}
		i++;
		if (!map[i])
		{
			trimed_last_l = ft_strtrim(map[i - 1], " \t");
			if (check_first_last_line(trimed_last_l))
				return (free(trimed_last_l), (1));
			free(trimed_last_l);
		}
	}
	if (last_catch_error(map, cub))
		return (1);
	return (0);
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

void	read_file(t_cub *cub, t_raycaste *caste)
{
	cub->line = get_next_line(cub->fd);
	if (!cub->line)
	{
		ft_free(cub);
		exit(printf(RED "Empty file\n" RESET));
	}
	process_file_lines(cub, caste);
}
