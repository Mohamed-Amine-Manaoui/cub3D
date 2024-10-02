#include "../_includes/cub3d.h"

int	find_start(char **map)
{
	char	*trim_map;
	int		start;

	start = 0;
	while (map[start])
	{
		trim_map = ft_strtrim(map[start], " \t\n");
		if (trim_map[0] != '\0')
		{
			free(trim_map);
			return (start);
		}
		free(trim_map);
		start++;
	}
	return (start);
}

int	find_end(char **map, int start)
{
	char	*trim_map;
	int		end;

	end = start;
	while (map[end])
		end++;
	end--;
	while (end > start)
	{
		trim_map = ft_strtrim(map[end], " \t\n");
		if (trim_map[0] != '\0')
		{
			free(trim_map);
			return (end);
		}
		free(trim_map);
		end--;
	}
	return (end);
}

void	resize_map(char **map, t_cub *cub)
{
	int	start;
	int	end;
	int	i;
	int	j;

	start = find_start(map);
	end = find_end(map, start);
	free_split(cub->caste_info->map);
	cub->caste_info->map = malloc(sizeof(char *) * (end - start + 2));
	i = start;
	j = 0;
	while (i <= end)
	{
		cub->caste_info->map[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	cub->caste_info->map[j] = NULL;
}
