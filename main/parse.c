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
	if (cub->redirect_symbol)
		free(cub->redirect_symbol);
	cub->redirect_symbol = ft_strtrim(tmp, " \t\n");
	free(tmp);
	if (cub->redirect_symbol[0] == '\0')
	{
		free(cub->redirect_symbol);
		cub->redirect_symbol = NULL;
	}
	tmp = NULL;
	j--;
	k = 0;
	j = j + i + 1;
	while (str[k + j])
		k++;
	tmp = ft_substr(str, j, k);
	if (cub->redirect_file)
		free(cub->redirect_file);
	cub->redirect_file = ft_strtrim(tmp, "\t \n");
	if (cub->redirect_file[0] == '\0')
	{
		free(cub->redirect_file);
		cub->redirect_file = NULL;
	}
	free(tmp);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
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

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
		return (free(ptr), NULL);
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
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
			break ;
		}
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
}
