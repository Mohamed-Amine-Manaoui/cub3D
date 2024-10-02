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

// int	valid_character_map(char *map, int *flag, t_cub *cub)
// {
// 	char	*trim_line;
// 	int		j;

// 	trim_line = ft_strtrim(map, " \t\n");
// 	if (!*flag && check_first_last_line(trim_line) != 0)
// 		return (free(trim_line), (1));
// 	*flag = 1;
// 	j = 0;
// 	while (trim_line[j])
// 	{
// 		if (trim_line[0] != '1' || trim_line[ft_strlen(trim_line) - 1] != '1')
// 			return (free(trim_line), (1));
// 		if (trim_line[j] != '1' && trim_line[j] != '0' && (trim_line[j] != 32
// 				|| trim_line[j] != '\t') && trim_line[j] != 'N')
// 			return (free(trim_line), (1));
// 		if (trim_line[j] == 'N')
// 			cub->flag_p++;
// 		j++;
// 	}
// 	free(trim_line);
// 	trim_line = NULL;
// 	return (0);
// }

// void	resize_map(char **map, t_cub *cub)
// {
// 	char	*trim_map;
// 	int		i;
// 	int		j;
// 	int		start;
// 	int		end;

// 	start = 0;
// 	while (map[start])
// 	{
// 		trim_map = ft_strtrim(map[start], " \t\n");
// 		if (trim_map[0] != '\0')
// 		{
// 			free(trim_map);
// 			break ;
// 		}
// 		free(trim_map);
// 		start++;
// 	}
// 	end = start;
// 	while (map[end])
// 		end++;
// 	end--;
// 	while (end > start)
// 	{
// 		trim_map = ft_strtrim(map[end], " \t\n");
// 		if (trim_map[0] != '\0')
// 		{
// 			free(trim_map);
// 			break ;
// 		}
// 		free(trim_map);
// 		end--;
// 	}
// 	free_split(cub->caste_info->map);
// 	cub->caste_info->map = malloc(sizeof(char *) * (end - start + 2));
// 	i = start;
// 	j = 0;
// 	while (i <= end)
// 	{
// 		cub->caste_info->map[j] = ft_strdup(map[i]);
// 		i++;
// 		j++;
// 	}
// 	cub->caste_info->map[j] = NULL;
// }

// int	find_start(char **map)
// {
// 	char	*trim_map;
// 	int		start;

// 	start = 0;
// 	while (map[start])
// 	{
// 		trim_map = ft_strtrim(map[start], " \t\n");
// 		if (trim_map[0] != '\0')
// 		{
// 			free(trim_map);
// 			return (start);
// 		}
// 		free(trim_map);
// 		start++;
// 	}
// 	return (start);
// }

// int	find_end(char **map, int start)
// {
// 	char	*trim_map;
// 	int		end;

// 	end = start;
// 	while (map[end])
// 		end++;
// 	end--;
// 	while (end > start)
// 	{
// 		trim_map = ft_strtrim(map[end], " \t\n");
// 		if (trim_map[0] != '\0')
// 		{
// 			free(trim_map);
// 			return (end);
// 		}
// 		free(trim_map);
// 		end--;
// 	}
// 	return (end);
// }

// void	resize_map(char **map, t_cub *cub)
// {
// 	int	start;
// 	int	end;
// 	int	i;
// 	int	j;

// 	start = find_start(map);
// 	end = find_end(map, start);
// 	free_split(cub->caste_info->map);
// 	cub->caste_info->map = malloc(sizeof(char *) * (end - start + 2));
// 	i = start;
// 	j = 0;
// 	while (i <= end)
// 	{
// 		cub->caste_info->map[j] = ft_strdup(map[i]);
// 		i++;
// 		j++;
// 	}
// 	cub->caste_info->map[j] = NULL;
// }

// int	any_empty_line(char **map)
// {
// 	int		i;
// 	char	*trim;

// 	i = 0;
// 	while (map[i])
// 	{
// 		trim = ft_strtrim(map[i], " \t\n");
// 		if (trim[0] == '\0')
// 			return (free(trim), 1);
// 		free(trim);
// 		i++;
// 	}
// 	return (0);
// }

int	trim_decale(char **map, int i, int j)
{
	char	*trim;

	trim = ft_strtrim(map[i + 1], " \t\n");
	if (i > 0 && ft_strlen(trim) <= (size_t)j)
		return (free(trim), 1);
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

// int	decalage_line(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (map[++i])
// 	{
// 		j = -1;
// 		while (map[i][++j])
// 		{
// 			if (map[i][j] == '0' || map[i][j] == 'N')
// 			{
// 				if (map[i][j + 1] && !(map[i][j + 1] == '0' || map[i][j
// 						+ 1] == '1' || map[i][j + 1] == 'N'))
// 					return (1);
// 				if (j > 0 && !(map[i][j - 1] == '0' || map[i][j - 1] == '1'
// 						|| map[i][j - 1] == 'N'))
// 					return (1);
// 				if (trim_decale(map, i, j))
// 					return (1);
// 			}
// 		}
// 	}
// 	return (0);
// }

// int	last_catch_error(char **map, t_cub *cub)
// {
// 	if (cub->flag_p != 1)
// 		return (1);
// 	resize_map(map, cub);
// 	if (any_empty_line(cub->caste_info->map))
// 		return (1);
// 	if (decalage_line(cub->caste_info->map))
// 		return (1);
// 	return (0);
// }

// int	is_valid_map(char **map, t_cub *cub)
// {
// 	char	*trimed_last_l;

// 	int(i), (flag);
// 	flag = 0;
// 	trimed_last_l = NULL;
// 	i = 0;
// 	while (map[i])
// 	{
// 		if (map[i][0] != '\0')
// 		{
// 			if (valid_character_map(map[i], &flag, cub))
// 				return (1);
// 		}
// 		i++;
// 		if (!map[i])
// 		{
// 			trimed_last_l = ft_strtrim(map[i - 1], " \t");
// 			if (check_first_last_line(trimed_last_l))
// 				return (free(trimed_last_l), (1));
// 			free(trimed_last_l);
// 		}
// 	}
// 	if (last_catch_error(map, cub))
// 		return (1);
// 	return (0);
// }

// void	read_file(t_cub *cub, t_raycaste *caste)
// {
// 	char	**clone_map;

// 	cub->line = get_next_line(cub->fd);
// 	if (!cub->line)
// 		(exit(printf(RED "Empty file\n" RESET)));
// 	while (cub->line)
// 	{
// 		skip_whitespaces(cub, cub->line);
// 		if (cub->redirect_symbol && cub->redirect_file)
// 			check_current_line(cub, caste);
// 		else if (cub->redirect_symbol && !cub->redirect_file)
// 			(printf(RED " %s :xpm file not found !!\n" RESET,
// 					cub->redirect_symbol), ft_free(cub), free(cub->line),
// 				ft_free_symbol(cub), exit(1));
// 		// read  map
// 		if (cub->count == 6)
// 		{
// 			free(cub->line);
// 			cub->line = get_next_line(cub->fd);
// 			if (!cub->line)
// 			{
// 				(ft_free(cub));
// 				free_caste_struct(caste);
// 				exit(printf(RED "Map not found\n" RESET));
// 			}
// 			while (cub->line)
// 			{
// 				caste->map = ft_realloc(caste->map, sizeof(char *) * caste->row,
// 						sizeof(char *) * (caste->row + 2));
// 				caste->trimmed_line = ft_strtrim(cub->line, "\n");
// 				caste->map[caste->row] = ft_strdup(caste->trimmed_line);
// 				free(caste->trimmed_line);
// 				caste->map[caste->row + 1] = NULL;
// 				caste->row++;
// 				free(cub->line);
// 				cub->line = get_next_line(cub->fd);
// 			}
// 			// parse map
// 			clone_map = duplicate_string(caste->map);
// 			if (is_valid_map(clone_map, cub))
// 			{
// 				(ft_free(cub), free_split(clone_map));
// 				free_split(caste->map);
// 				free_caste_struct(caste);
// 				printf(RED "Invalid Map\n" RESET), exit(1);
// 			}
// 			free_split(clone_map);
// 			break ;
// 		}
// 		free(cub->line);
// 		cub->line = get_next_line(cub->fd);
// 	}
// 	if (!cub->line)
// 		(exit(printf(RED "Empty file\n" RESET)));
// }

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
