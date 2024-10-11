#include "../_includes/cub3d.h"

void	setup_line(t_mlx *mlx, int x2, int y2)
{
	int	x1;
	int	y1;

	x1 = mlx->x_player;
	y1 = mlx->y_player;
	if (!mlx)
		return ;
	mlx->dx = ft_abs(x2 - x1);
	mlx->dy = ft_abs(y2 - y1);
	mlx->err = mlx->dx - mlx->dy;
	if (x1 < x2)
		mlx->sx = 1;
	else
		mlx->sx = -1;
	if (y1 < y2)
		mlx->sy = 1;
	else
		mlx->sy = -1;
}

void	draw_line(t_mlx *mlx, int x2, int y2)
{
	int	x1;
	int	y1;

	x1 = mlx->x_player;
	y1 = mlx->y_player;
	setup_line(mlx, x2, y2);
	while (x1 != x2 || y1 != y2)
	{
		my_mlx_pixel_put(mlx, x1, y1, 0xFF0000);
		mlx->e2 = 2 * mlx->err;
		if (mlx->e2 > -mlx->dy)
		{
			mlx->err -= mlx->dy;
			x1 += mlx->sx;
		}
		if (mlx->e2 < mlx->dx)
		{
			mlx->err += mlx->dx;
			y1 += mlx->sy;
		}
	}
	my_mlx_pixel_put(mlx, x2, y2, 0xFF0000);
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
		color = 0x0000FF;
	else if (c == '0' || symbolic_character(c))
		color = 0xFFFFFF;
	else
		color = 0x808080;
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
