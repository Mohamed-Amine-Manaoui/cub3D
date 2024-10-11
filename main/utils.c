#include "../_includes/cub3d.h"

int	check_alpha(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!av[i])
		return (1);
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	handle_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == 32)
			i++;
		if (((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= 48 && str[i
					+ 1] <= 57)) || check_alpha(str))
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

char	**handle_whitespaces(char **av)
{
	int		i;
	int		j;
	char	**tmp;
	int		count;

	count = 0;
	while (av[count])
		count++;
	tmp = malloc(sizeof(char *) * (count + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == 32 || av[i][j] == 9)
			j++;
		tmp[i] = ft_strdup(av[i] + j);
		j = ft_strlen(tmp[i]) - 1;
		while (j >= 0 && (tmp[i][j] == 32 || tmp[i][j] == 9))
			j--;
		tmp[i][j + 1] = '\0';
		i++;
	}
	return (tmp[i] = NULL, tmp);
}

char	**duplicate_string(char **map)
{
	int		i;
	char	**nw_map;
	int		j;

	i = 0;
	while (map[i] != NULL)
		i++;
	nw_map = malloc((i + 1) * sizeof(char *));
	if (!nw_map)
		return (NULL);
	j = 0;
	while (j < i)
	{
		nw_map[j] = ft_strdup(map[j]);
		j++;
	}
	nw_map[i] = NULL;
	return (nw_map);
}

int	is_wall(t_mlx *mlx, double next_x, double next_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(next_x / 48);
	map_y = (int)(next_y / 48);
	if (mlx->caste_info->map[map_y][map_x] == '1')
		return (1);
	return (0);
}
