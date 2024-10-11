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

int	key_hook(int keycode, t_mlx *mlx)
{
	double	next_x;
	double	next_y;

	if (keycode == ESC)
		ft_close(mlx);
	else if (keycode == W)
		key_w(mlx, &next_x, &next_y);
	else if (keycode == S)
		key_s(mlx, &next_x, &next_y);
	else if (keycode == D)
		key_d(mlx, &next_x, &next_y);
	else if (keycode == A)
		key_a(mlx, &next_x, &next_y);
	else if (keycode == UP)
		mlx->line_angle += 0.1;
	else if (keycode == DOWN)
		mlx->line_angle -= 0.1;
	after_use_key(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub		cub;
	t_raycaste	caste;
	t_mlx		mlx;

	if (ac != 2)
	{
		printf(RED "Sorry but this program does not accept more than two arguments! (Ghyrha ^^)\n" RESET);
		exit(EXIT_FAILURE);
	}
	valid_extension(av[1]);
	init_structs(&cub, &caste, &mlx, av);
	read_file(&cub, &caste);
	calcul_with_height(&mlx, &caste);
	mlx.ptr = mlx_init();
	mlx.ptr_win = mlx_new_window(mlx.ptr, mlx.w_h_map[0] * 48, mlx.w_h_map[1]
			* 48, "siri ghiyriha !!");
	mlx.img = mlx_new_image(mlx.ptr, mlx.w_h_map[0] * 48, mlx.w_h_map[1] * 48);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
			&mlx.endian);
	paint_map(&caste, &mlx);
	mlx_hook(mlx.ptr_win, KeyPress, KeyPressMask, key_hook, &mlx);
	mlx_hook(mlx.ptr_win, 17, 0, (void *)ft_close, &mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.ptr_win, mlx.img, 0, 0);
	mlx_loop(mlx.ptr);
	return (0);
}
