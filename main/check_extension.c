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

void	xpm_extension(char *s, t_cub *cub)
{
	char	*extension;
	char	**tmp;

	tmp = exec_split(s, " \t");
	if (tmp[1])
	{
		printf(RED " %s : invalid xpm file (Ghyrha ^^)\n" RESET,
			cub->redirect_file);
		(ft_free(cub), free(cub->line), ft_free_symbol(cub));
		(free_split(tmp), exit(1));
	}
	free_split(tmp);
	extension = ft_strrchr(s, '.');
	if (!extension)
	{
		printf(RED " %s : invalid xpm file (Ghyrha ^^)\n" RESET,
			cub->redirect_file);
		(ft_free(cub), free(cub->line), ft_free_symbol(cub), exit(1));
	}
	if (ft_strcmp(extension, ".xpm"))
	{
		printf(RED "%s : Invalid xpm extension (Ghyrha ^^)\n" RESET,
			cub->redirect_file);
		(ft_free(cub), free(cub->line), ft_free_symbol(cub), exit(1));
	}
}

void	calcul_with_height(t_mlx *mlx, t_raycaste *caste)
{
	int	i;

	i = 0;
	mlx->w_h_map[0] = ft_strlen(caste->map[0]);
	while (caste->map[i])
	{
		if (ft_strlen(caste->map[i + 1]) > mlx->w_h_map[0])
		{
			mlx->w_h_map[0] = ft_strlen(caste->map[i + 1]);
		}
		i++;
	}
	mlx->w_h_map[1] = i;
}
