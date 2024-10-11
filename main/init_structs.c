#include "../_includes/cub3d.h"

void	init_cub(t_cub *cub, char **av)
{
	cub->count = 0;
	cub->flag_p = 0;
	cub->flag_no = 0;
	cub->flag_so = 0;
	cub->flag_ea = 0;
	cub->flag_we = 0;
	cub->flag_sky = 0;
	cub->flag_floor = 0;
	cub->redirect_file = NULL;
	cub->redirect_symbol = NULL;
	cub->name_file = ft_strdup(av[1]);
	cub->fd = open(cub->name_file, O_RDONLY);
	if (cub->fd == -1)
		(perror(RED "open" RESET), free(cub->name_file), exit(EXIT_FAILURE));
}

void	init_caste(t_raycaste *caste)
{
	caste->row = 0;
	caste->map = NULL;
	caste->no_file = NULL;
	caste->so_file = NULL;
	caste->ea_file = NULL;
	caste->we_file = NULL;
	caste->no_symbol = NULL;
	caste->so_symbol = NULL;
	caste->ea_symbol = NULL;
	caste->we_symbol = NULL;
	caste->trimmed_line = NULL;
}

void	init_structs(t_cub *cub, t_raycaste *caste, t_mlx *mlx, char **av)
{
	ft_memset(cub, 0, sizeof(*cub));
	ft_memset(caste, 0, sizeof(*caste));
	ft_memset(mlx, 0, sizeof(*mlx));
	cub->caste_info = caste;
	mlx->caste_info = caste;
	mlx->cub_info = cub;
	init_caste(caste);
	init_cub(cub, av);
}
