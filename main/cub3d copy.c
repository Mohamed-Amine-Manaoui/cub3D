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

// void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// void	draw_cercle1(t_mlx *mlx, int Xp, int Yp, int radius)
// {
// 	int	x;
// 	int	y;

// 	x = Xp - radius;
// 	while (x <= Xp + radius)
// 	{
// 		y = Yp - radius;
// 		while (y <= Yp + radius)
// 		{
// 			if (pow((x - Xp), 2) + pow((y - Yp), 2) <= pow(radius, 2))
// 			{
// 				my_mlx_pixel_put(mlx, x, y, 0xFF0000);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	draw_cercle(t_mlx *mlx, int Xp, int Yp, int radius)
// {
// 	int	x;
// 	int	y;

// 	x = Xp - radius;
// 	while (x <= Xp + radius)
// 	{
// 		y = Yp - radius;
// 		while (y <= Yp + radius)
// 		{
// 			if (pow((x - Xp), 2) + pow((y - Yp), 2) <= pow(radius, 2))
// 			{
// 				mlx_pixel_put(mlx->ptr, mlx->ptr_win, x, y,  0x808080);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	paint_square(t_mlx *mlx, int col, int row, char c)
// {
// 	int	j;
// 	int	i;
// 	int	color;

// 	if (c == '1')
// 		color = 0x0000FF;                       // (blue)
// 	else if (c == '0' || symbolic_character(c)) // (white)
// 		color = 0xFFFFFF;
// 	else
// 		color = 0x808080; // (gray)
// 	i = 0;
// 	while (i < SQUARE_SIZE)
// 	{
// 		j = 0;
// 		while (j < SQUARE_SIZE)
// 		{
// 			my_mlx_pixel_put(mlx, row * SQUARE_SIZE + j, col * SQUARE_SIZE + i,
// 				color);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (symbolic_character(c))
// 	{
// 		my_mlx_pixel_put(mlx, mlx->x_player * SQUARE_SIZE + SQUARE_SIZE / 2,
// 			mlx->y_player * SQUARE_SIZE + SQUARE_SIZE / 2,  0x808080);
// 		draw_cercle(mlx, mlx->x_player * SQUARE_SIZE + SQUARE_SIZE / 2,
// 			mlx->y_player * SQUARE_SIZE + SQUARE_SIZE / 2, SQUARE_SIZE / 4);
// 	}
// }

// void draw_cercle(t_mlx *mlx, int Xp, int Yp, int radius)
// {
//     int x;
//     int y;

//    x = Xp - radius;
//    while (x <= Xp + radius)
//    {
//    		y = Yp - radius;
// 		while (y <= Yp + radius)
// 		{
// 			if (pow((x - Xp), 2) + pow((y -Yp), 2) <= pow(radius, 2))
// 			{
// 					mlx_pixel_put(mlx->ptr, mlx->ptr_win, x, y, 0xFF0000);
// 			}
// 			y++;
// 		}
// 		x++;
//    }
// }
// void	paint_square(t_mlx *mlx, int col, int row, char c)
// {
// 	int	j;
// 	int	i;
// 	int color;

// 	if (c == '1')
// 		color = 0x0000FF; //(bleu)
// 	else if (c == '0' || symbolic_character(c)) // (blanc)
// 		color = 0xFFFFFF; // (blanc)
// 	else
// 		color = 0x808080; // (gray)

// 	i = 0;
// 	while (i < SQUARE_SIZE)
// 	{
// 		j = 0;
// 		while (j < SQUARE_SIZE)
// 		{
// 			mlx_pixel_put(mlx->ptr, mlx->ptr_win, row * SQUARE_SIZE + j, col
// 				* SQUARE_SIZE + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (symbolic_character(c))
// 	{
// 	mlx_pixel_put(mlx->ptr, mlx->ptr_win,
// 		mlx->x_player * SQUARE_SIZE + SQUARE_SIZE / 2,
// 		mlx->y_player * SQUARE_SIZE + SQUARE_SIZE / 2, 0xFF0000);
// 	draw_cercle(mlx, mlx->x_player * SQUARE_SIZE + SQUARE_SIZE / 2,
// 	mlx->y_player * SQUARE_SIZE + SQUARE_SIZE / 2,
// 		SQUARE_SIZE / 4);
// 	}

// }

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

// void	clear_image(t_mlx *mlx)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
//     calcul_with_height(mlx, mlx->caste_info);
// 	while (y < mlx->w_h_map[1])
// 	{
// 		x = 0;
// 		while (x < mlx->w_h_map[0])
// 		{
// 			my_mlx_pixel_put(mlx, x, y, 0x000000);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	paint_map(t_raycaste *caste, t_mlx *mlx)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	// clear_image(mlx);
// 	while (caste->map[i])
// 	{
// 		j = 0;
// 		while (caste->map[i][j])
// 		{
// 			if (symbolic_character(caste->map[i][j]))
// 			{
// 				mlx->x_player = j;
// 				mlx->y_player = i;
// 			}
// 			paint_square(mlx, i, j, caste->map[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	key_hook(int keyhook, t_mlx *mlx)
// {
// 	if (keyhook == ESC)
// 	{
// 		exit(0);
// 	}
// 	else if (keyhook == A)
//     {

//     }

// 	return (0);
// }

// int	main(int ac, char **av)
// {
// 	t_cub		cub;
// 	t_raycaste	caste;
// 	t_mlx		mlx;

// 	if (ac != 2)
// 	{
// 		printf(RED "Sorry but this program does not accept more than two arguments! (Ghyrha ^^)\n" RESET);
// 		exit(EXIT_FAILURE);
// 	}
// 	cub.caste_info = &caste;
// 	mlx.caste_info = &caste;
// 	valid_extension(av[1]);
// 	init_structs(&cub, &caste, av);
// 	read_file(&cub, &caste);
// 	// if (!caste.map)
// 	//     return (printf(RED "Empty File !!\n" RESET));
// 	// printf("map : %c\n", caste.map[1][5]);
// 	calcul_with_height(&mlx, &caste);
// 	mlx.ptr = mlx_init();
// 	mlx.ptr_win = mlx_new_window(mlx.ptr, mlx.w_h_map[0] * 48, mlx.w_h_map[1]
// 			* 48, "siri ghiyriha !!");
// 	mlx.img = mlx_new_image(mlx.ptr, mlx.w_h_map[0] * 48, mlx.w_h_map[1] * 48);
// 	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
// 			&mlx.endian);
// 	paint_map(&caste, &mlx);
// 	// mlx_put_image_to_window(mlx.ptr, mlx.ptr_win, mlx.img, 0, 0);
// 	mlx_key_hook(mlx.ptr_win, key_hook, &mlx);
// 	mlx_loop(mlx.ptr);
// 	return (0);
// }

// #define MOVE_STEP 2

// void draw_cercle(t_mlx *mlx, int Xp, int Yp, int radius)
// {
//     int x;
//     int y;

//    x = Xp - radius;
//    while (x <= Xp + radius)
//    {
//    		y = Yp - radius;
// 		while (y <= Yp + radius)
// 		{
// 			if (pow((x - Xp), 2) + pow((y -Yp), 2) <= pow(radius, 2))
// 			{
// 					mlx_pixel_put(mlx->ptr, mlx->ptr_win, x, y, 0xFF0000);
// 			}
// 			y++;
// 		}
// 		x++;
//    }
// }
// void paint_square(t_mlx *mlx, int col, int row, char c)
// {
// 	int	j;
// 	int	i;
// 	int color;

// 	if (c == '1')
// 		color = 0x0000FF; //(blue)
// 	else if (c == '0' || symbolic_character(c)) // (white)
// 		color = 0xFFFFFF; // (white)
// 	else
// 		color = 0x808080; // (gray)

// 	i = 0;
// 	while (i < SQUARE_SIZE)
// 	{
// 		j = 0;
// 		while (j < SQUARE_SIZE)
// 		{
// 			mlx_pixel_put(mlx->ptr, mlx->ptr_win, row * SQUARE_SIZE + j, col
// 				* SQUARE_SIZE + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (symbolic_character(c))
// 	{
// 		draw_cercle(mlx, mlx->player_x_pos + SQUARE_SIZE / 2,
// 			mlx->player_y_pos + SQUARE_SIZE / 2, SQUARE_SIZE / 4);
// 	}
// }

// void paint_map(t_raycaste *caste, t_mlx *mlx)
// {
//     int i;
//     int j;

//     i = 0;
//     while (caste->map[i])
//     {
//         j = 0;
//         while (caste->map[i][j])
//         {
//             if (symbolic_character(caste->map[i][j]))
//             {
//                 mlx->x_player = j;
//                 mlx->y_player = i;
//             }
//             paint_square(mlx, i, j, caste->map[i][j]);
//             j++;
//         }
//         i++;
//     }
// }

// int key_hook(int keyhook, t_mlx *mlx)
// {
// 	paint_map(mlx->caste_info, mlx);

// 	if (keyhook == ESC)
// 		exit(0);
// 	else if (keyhook == A)
// 		mlx->player_x_pos -= MOVE_STEP;
// 	else if (keyhook == D)
// 		mlx->player_x_pos += MOVE_STEP;
// 	else if (keyhook == W)
// 		mlx->player_y_pos -= MOVE_STEP;
// 	else if (keyhook == S)
// 		mlx->player_y_pos += MOVE_STEP;

// 	paint_map(mlx->caste_info, mlx);

// 	return (0);
// }

// int	main(int ac, char **av)
// {
// 	t_cub		cub;
// 	t_raycaste	caste;
// 	t_mlx		mlx;

// 	if (ac != 2)
// 	{
// 		printf(RED "Sorry but this program does not accept more than two arguments! (Ghyrha ^^)\n" RESET);
// 		exit(EXIT_FAILURE);
// 	}
// 	cub.caste_info = &caste;
// 	mlx.caste_info = &caste;
// 	valid_extension(av[1]);
// 	init_structs(&cub, &caste, av);
// 	read_file(&cub, &caste);
// 	calcul_with_height(&mlx, &caste);
// 	mlx.ptr = mlx_init();
// 	mlx.ptr_win = mlx_new_window(mlx.ptr, mlx.w_h_map[0] * 48, mlx.w_h_map[1]
///	* 48, "siri ghiyriha !!");
// 	mlx.img = mlx_new_image(mlx.ptr, mlx.w_h_map[0] * 48, mlx.w_h_map[1] * 48);
// 	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
// &mlx.endian);

// 	mlx.player_x_pos = mlx.x_player * SQUARE_SIZE + SQUARE_SIZE / 2;
// 	mlx.player_y_pos = mlx.y_player * SQUARE_SIZE + SQUARE_SIZE / 2;

// 	paint_map(&caste, &mlx);
// 	mlx_key_hook(mlx.ptr_win, key_hook, &mlx);
// 	mlx_loop(mlx.ptr);
// 	return (0);
// }

#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define MOVE_STEP 2

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
		char *dst;

	if (x >= 0 && x < mlx->w_h_map[0] * 48 && y >= 0 && y < mlx->w_h_map[1]
		* 48)
	{
		dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
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
		color = 0x0000FF;                       // (blue)
	else if (c == '0' || symbolic_character(c)) // (white)
		color = 0xFFFFFF;                       // (white)
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
	{
		draw_cercle(mlx, mlx->player_x_pos + SQUARE_SIZE / 2, mlx->player_y_pos
			+ SQUARE_SIZE / 2, SQUARE_SIZE / 4);
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

#define KeyPress 2
#define KeyPressMask (1L << 0)

int	key_hook(int keyhook, t_mlx *mlx)
{
	// Clear the image by creating a new image
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->ptr, mlx->w_h_map[0] * 48, mlx->w_h_map[1]
			* 48);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	// Update player position based on key press
	if (keyhook == ESC)
		exit(0);
	else if (keyhook == A)
		mlx->player_x_pos -= MOVE_STEP;
	else if (keyhook == D)
		mlx->player_x_pos += MOVE_STEP;
	else if (keyhook == W)
		mlx->player_y_pos -= MOVE_STEP;
	else if (keyhook == S)
		mlx->player_y_pos += MOVE_STEP;
	// Redraw the map and player
	paint_map(mlx->caste_info, mlx);
	// Put the updated image to the window
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
	// Create an image to draw on
	mlx.img = mlx_new_image(mlx.ptr, mlx.w_h_map[0] * 48, mlx.w_h_map[1] * 48);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
			&mlx.endian);
	mlx.player_x_pos = mlx.x_player * SQUARE_SIZE + SQUARE_SIZE / 2;
	mlx.player_y_pos = mlx.y_player * SQUARE_SIZE + SQUARE_SIZE / 2;
	paint_map(&caste, &mlx);
	// Put the initial image to the window
	mlx_put_image_to_window(mlx.ptr, mlx.ptr_win, mlx.img, 0, 0);
	// Change this line to use mlx_hook
	mlx_hook(mlx.ptr_win, KeyPress, KeyPressMask, key_hook, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
