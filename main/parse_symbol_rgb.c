#include "../_includes/cub3d.h"

int	valid_rgb(char **av)
{
	int		i;
	int		count;
	char	**tmp;
	int		r;

	count = 0;
	i = 0;
	tmp = handle_whitespaces(av);
	if (tmp[0] && tmp[1] && tmp[2])
	{
	while (tmp[i])
	{
		if (handle_error(tmp[i]) == -1)
		{
			return (free_split(tmp), 1);
		}
		r = ft_atoi(tmp[i]);
		if (r < 0 || r > 255)
			return (1);
		i++;
	}
	}
	else
		return (free_split(tmp), 1);
	return (free_split(tmp), 0);
}

void	check_current_line(t_cub *cub, t_raycaste *caste)
{
	if (ft_strcmp(cub->redirect_symbol, "NO") == 0 && !cub->flag_no)
		(xpm_extension(cub->redirect_file, cub), store_symbol(&caste->no_symbol,
				&caste->no_file, cub, &cub->flag_no));
	else if (ft_strcmp(cub->redirect_symbol, "SO") == 0 && !cub->flag_so)
		(xpm_extension(cub->redirect_file, cub), store_symbol(&caste->so_symbol,
				&caste->so_file, cub, &cub->flag_so));
	else if (ft_strcmp(cub->redirect_symbol, "EA") == 0 && !cub->flag_ea)
		(xpm_extension(cub->redirect_file, cub), store_symbol(&caste->ea_symbol,
				&caste->ea_file, cub, &cub->flag_ea));
	else if (ft_strcmp(cub->redirect_symbol, "WE") == 0 && !cub->flag_we)
		(xpm_extension(cub->redirect_file, cub), store_symbol(&caste->we_symbol,
				&caste->we_file, cub, &cub->flag_we));
	else if (ft_strcmp(cub->redirect_symbol, "F") == 0 && !cub->flag_floor)
		(floor_sky(cub), store_rgb(caste->rgb_floor, cub, &cub->flag_floor),
			free_split(cub->rgb_));
	else if (ft_strcmp(cub->redirect_symbol, "C") == 0 && !cub->flag_sky)
		(floor_sky(cub), store_rgb(caste->rgb_sky, cub, &cub->flag_sky),
			free_split(cub->rgb_));
	else
		(printf(RED "NOTHING\n" RESET), ft_free_symbol(cub), free(cub->line),
			ft_free(cub), exit(1));
	cub->count++;
}

void	floor_sky(t_cub *cub)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cub->redirect_file[i])
	{
		if (cub->redirect_file[i] == ',')
			count++;
		i++;
	}
	if (count > 2)
	{
		(free(cub->line), ft_free_symbol(cub), ft_free(cub));
		exit(printf(RED "INVALID RGB\n" RESET));
	}
	cub->rgb_ = exec_split(cub->redirect_file, ",");
	if (valid_rgb(cub->rgb_))
	{
		printf(RED "invalid RGB\n" RESET);
		(free(cub->line), ft_free(cub), ft_free_symbol(cub));
		free_split(cub->rgb_);
		exit(1);
	}
}

void	store_rgb(int *tab, t_cub *cub, int *flag)
{
	tab[0] = ft_atoi(cub->rgb_[0]);
	tab[1] = ft_atoi(cub->rgb_[1]);
	tab[2] = ft_atoi(cub->rgb_[2]);
	*flag = 1;
}

void	store_symbol(char **symbol, char **file, t_cub *cub, int *flag)
{
	*symbol = ft_strdup(cub->redirect_symbol);
	*file = ft_strdup(cub->redirect_file);
	*flag = 1;
}

