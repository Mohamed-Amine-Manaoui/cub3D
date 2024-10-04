#include "../_includes/cub3d.h"

void	print_file(t_cub *cub)
{
	char	*line;

	line = get_next_line(cub->fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(cub->fd);
	}
}

void	print_map(t_raycaste *caste)
{
	size_t	i;

	i = 0;
	while (caste->map[i] != NULL)
	{
		if (!caste->map[i])
			break ;
		printf("%s\n", caste->map[i]);
		i++;
	}
}

void	init_structs(t_cub *cub, t_raycaste *caste, char **av)
{
	caste->row = 0;
	cub->count = 0;
	cub->flag_p = 0;
	cub->flag_no = 0;
	cub->flag_so = 0;
	cub->flag_ea = 0;
	cub->flag_we = 0;
	cub->flag_sky = 0;
	cub->flag_floor = 0;
	caste->map = NULL;
	caste->no_file = NULL;
	caste->so_file = NULL;
	caste->ea_file = NULL;
	caste->we_file = NULL;
	caste->no_symbol = NULL;
	caste->so_symbol = NULL;
	caste->ea_symbol = NULL;
	caste->we_symbol = NULL;
	cub->redirect_file = NULL;
	caste->trimmed_line = NULL;
	cub->redirect_symbol = NULL;
	cub->name_file = ft_strdup(av[1]);
	cub->fd = open(cub->name_file, O_RDONLY);
	if (cub->fd == -1)
		(perror(RED "open" RESET), free(cub->name_file), exit(EXIT_FAILURE));
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

#include <math.h>

void draw_cercle(t_mlx *mlx, int Xp, int Yp, int radius)
{
    int x;
    int y;

   x = Xp - radius;
   while (x <= Xp + radius)
   {
   		y = Yp - radius;
		while (y <= Yp + radius)
		{
			if (pow((x - Xp), 2) + pow((y -Yp), 2) <= pow(radius, 2))
			{
				 mlx_pixel_put(mlx->ptr, mlx->ptr_win, x, y, 0xFF0000);
			}
			y++;
		}
		x++;
   }
}
void	paint_square(t_mlx *mlx, int col, int row, char c)
{
	int	j;
	int	i;
	int color;

	if (c == '1')
		color = 0x0000FF; //(bleu)
	else if (c == '0' || symbolic_character(c)) // (blanc)
		color = 0xFFFFFF; // (blanc) 
	else 
		color = 0x808080; // (gray)


	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			mlx_pixel_put(mlx->ptr, mlx->ptr_win, row * SQUARE_SIZE + j, col
				* SQUARE_SIZE + i, color);
			j++;
		}
		i++;
	}
	if (symbolic_character(c))
	{
	mlx_pixel_put(mlx->ptr, mlx->ptr_win,
		mlx->x_player * SQUARE_SIZE + SQUARE_SIZE / 2,
		mlx->y_player * SQUARE_SIZE + SQUARE_SIZE / 2, 0xFF0000);
	draw_cercle(mlx, mlx->x_player * SQUARE_SIZE + SQUARE_SIZE / 2, 
	mlx->y_player * SQUARE_SIZE + SQUARE_SIZE / 2, 
		SQUARE_SIZE / 4);
	}

}

void	paint_map(t_raycaste *caste, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (caste->map[i])
	{
		j = 0;
		while (caste->map[i][j])
		{
			if (symbolic_character(caste->map[i][j])) 
			{
				mlx->x_player = j; 
				mlx->y_player = i;
			}
			paint_square(mlx, i, j, caste->map[i][j]); 
			j++;
		}
		i++;
	}
}

// hiya li gha tgad lfuctions dial error nxaellah (HHHHH)
int	main(int ac, char **av)
{
	t_cub		cub;
	t_raycaste	caste;
	t_mlx		mlx;

	if (ac != 2)
	{
		printf(RED "Sorry but this program does not accept more two arguments! (Ghyrha ^^)\n" RESET);
		exit(EXIT_FAILURE);
	}
	cub.caste_info = &caste;
	valid_extension(av[1]);
	init_structs(&cub, &caste, av);
	read_file(&cub, &caste);
	// print_map(&caste);
	if (!caste.map)
		return (printf(RED "Empty File !!\n" RESET));
	// if (caste.map)
	// 	free_split(caste.map);
	// ft_free(&cub);
	// free_caste_struct(&caste);
	// map 2D
	calcul_with_height(&mlx, &caste);
	mlx.ptr = mlx_init();
	mlx.ptr_win = mlx_new_window(mlx.ptr, mlx.w_h_map[0] * 48, mlx.w_h_map[1]
			* 48, "siri ghiyriha !!");
	paint_map(&caste, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
