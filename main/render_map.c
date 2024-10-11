#include "../_includes/cub3d.h"

void	render_paint_square(t_mlx *mlx, int col, int row, char c)
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
