#include "../_includes/cub3d.h"

void	ft_free(t_cub *cub)
{
	free(cub->name_file);
	free(cub->redirect_file);
	free(cub->redirect_symbol);
}

void ft_free_symbol (t_cub *cub)
{
	free(cub->caste_info->no_file);
	free(cub->caste_info->no_symbol);
	free(cub->caste_info->so_file);
	free(cub->caste_info->so_symbol);
	free(cub->caste_info->ea_file);
	free(cub->caste_info->ea_symbol);
	free(cub->caste_info->we_file);
	free(cub->caste_info->we_symbol);
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

void	free_caste_struct(t_raycaste *caste)
{
	free(caste->no_file);
	free(caste->so_file);
	free(caste->ea_file);
	free(caste->we_file);
	free(caste->no_symbol);
	free(caste->so_symbol);
	free(caste->ea_symbol);
	free(caste->we_symbol);
}
