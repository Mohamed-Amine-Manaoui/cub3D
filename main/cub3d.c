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

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_cercle(t_mlx *mlx, int Xp, int Yp, int radius)
{
	int	x;
	int	y;

	x = Xp - radius;
	while (x <= Xp + radius)
	{
		y = Yp - radius;
		while (y <= Yp + radius)
		{
			if (pow((x - Xp), 2) + pow((y - Yp), 2) <= pow(radius, 2))
			{
				my_mlx_pixel_put(mlx, x, y, 0xFF0000);
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
	int	color;

	if (c == '1')
		color = 0x0000FF;                       //(bleu)
	else if (c == '0' || symbolic_character(c)) // (blanc)
		color = 0xFFFFFF;                      
	else
		color = 0x808080; // (gray)
	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			my_mlx_pixel_put(mlx, row * SQUARE_SIZE + j, col * SQUARE_SIZE + i,
				color);
			j++;
		}
		i++;
	}
	if (symbolic_character(c))
		draw_cercle(mlx, mlx->x_player, mlx->y_player, 6);
}

void	render_paint_square(t_mlx *mlx, int col, int row, char c)
{
	int	j;
	int	i;
	int	color;

	if (c == '1')
		color = 0x0000FF;                       //(bleu)
	else if (c == '0' || symbolic_character(c)) // (blanc)
		color = 0xFFFFFF;                      
	else
		color = 0x808080; // (gray)
	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			my_mlx_pixel_put(mlx, row * SQUARE_SIZE + j, col * SQUARE_SIZE + i,
				color);
			j++;
		}
		i++;
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
				mlx->x_player = (j * SQUARE_SIZE) + (SQUARE_SIZE / 2);
				mlx->y_player = (i * SQUARE_SIZE) + (SQUARE_SIZE / 2);
			}
			paint_square(mlx, i, j, caste->map[i][j]);
			j++;
		}
		i++;
	}
}

void	render_map(t_raycaste *caste, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (caste->map[i])
	{
		j = 0;
		while (caste->map[i][j])
		{
			render_paint_square(mlx, i, j, caste->map[i][j]);
			j++;
		}
		i++;
	}
	draw_cercle(mlx, mlx->x_player, mlx->y_player, 6);
	my_mlx_pixel_put(mlx, mlx->x_player, mlx->y_player, 0x0000FF);
}

void	draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	// ila kant forbidden nsayboouha sahla
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	err = dx - dy;
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	while (x1 != x2 || y1 != y2)
	{
		my_mlx_pixel_put(mlx, x1, y1, color);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	int		x_end;
	int		y_end;
	double	line_length;
	double	speed;

	line_length = 40;
	speed = 3.0;
	if (keycode == ESC)
		exit(0);
	else if (keycode == W)
	{
		mlx->x_player += speed * cos(mlx->line_angle);
		mlx->y_player += speed * sin(mlx->line_angle);
	}
	else if (keycode == S)
	{
		mlx->x_player -= speed * cos(mlx->line_angle);
		mlx->y_player -= speed * sin(mlx->line_angle);
	}
	else if (keycode == A)
	{
		mlx->x_player -= speed * sin(mlx->line_angle);
		mlx->y_player += speed * cos(mlx->line_angle);
	}
	else if (keycode == D)
	{
		mlx->x_player += speed * sin(mlx->line_angle);
		mlx->y_player -= speed * cos(mlx->line_angle);
	}
	else if (keycode == UP)
	{
		mlx->line_angle += 0.1;
	}
	else if (keycode == DOWN)
	{
		mlx->line_angle -= 0.1;
	}
	mlx_clear_window(mlx->ptr, mlx->ptr_win);
	x_end = mlx->x_player + line_length * cos(mlx->line_angle);
	y_end = mlx->y_player + line_length * sin(mlx->line_angle);
	render_map(mlx->caste_info, mlx);
	draw_line(mlx, mlx->x_player, mlx->y_player, x_end, y_end, 0xFF0000);
	mlx_put_image_to_window(mlx->ptr, mlx->ptr_win, mlx->img, 0, 0);
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
	cub.caste_info = &caste;
	mlx.caste_info = &caste;
	valid_extension(av[1]);
	init_structs(&cub, &caste, av);
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
	mlx_put_image_to_window(mlx.ptr, mlx.ptr_win, mlx.img, 0, 0);
	mlx_loop(mlx.ptr);
	return (0);
}
