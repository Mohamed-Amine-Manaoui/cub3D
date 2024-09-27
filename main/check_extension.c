#include "../_includes/cub3d.h"

void	valid_extension(char *s)
{
	char	*extension;

	extension = ft_strrchr(s, '.');
	if (!extension)
	{
		printf(RED "Invalid File (Ghyrha ^^)\n" RESET);
		exit(1);
	}
	if (ft_strcmp(extension, ".cub"))
	{
		printf(RED "Invalid extension (Ghyrha ^^)\n" RESET);
		exit(1);
	}
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

void	xpm_extension(char *s, t_cub *cub)
{
	char	*extension;

	extension = ft_strrchr(s, '.');
	if (!extension)
	{
		printf(RED " %s : invalid xpm file (Ghyrha ^^)\n" RESET,
			cub->redirect_file);
		// free(cub->caste->no_symbol);
		ft_free(cub);
		free(cub->line);
		ft_free_symbol(cub);
		exit(1);
	}
	if (ft_strcmp(extension, ".xpm"))
	{
		printf(RED "%s : Invalid xpm extension (Ghyrha ^^)\n" RESET,
			cub->redirect_file);
		ft_free(cub);
		free(cub->line);
		ft_free_symbol(cub);
		exit(1);
	}
}
