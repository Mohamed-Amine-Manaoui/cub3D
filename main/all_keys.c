#include "../_includes/cub3d.h"

void	key_w(t_mlx *mlx, double *next_x, double *next_y)
{
	*next_x = mlx->x_player + SPEED * cos(mlx->line_angle);
	*next_y = mlx->y_player + SPEED * sin(mlx->line_angle);
	if (!is_wall(mlx, *next_x, *next_y))
	{
		mlx->x_player = *next_x;
		mlx->y_player = *next_y;
	}
}

void	key_s(t_mlx *mlx, double *next_x, double *next_y)
{
	*next_x = mlx->x_player - SPEED * cos(mlx->line_angle);
	*next_y = mlx->y_player - SPEED * sin(mlx->line_angle);
	if (!is_wall(mlx, *next_x, *next_y))
	{
		mlx->x_player = *next_x;
		mlx->y_player = *next_y;
	}
}

void	key_d(t_mlx *mlx, double *next_x, double *next_y)
{
	*next_x = mlx->x_player - SPEED * sin(mlx->line_angle);
	*next_y = mlx->y_player + SPEED * cos(mlx->line_angle);
	if (!is_wall(mlx, *next_x, *next_y))
	{
		mlx->x_player = *next_x;
		mlx->y_player = *next_y;
	}
}

void	key_a(t_mlx *mlx, double *next_x, double *next_y)
{
	*next_x = mlx->x_player + SPEED * sin(mlx->line_angle);
	*next_y = mlx->y_player - SPEED * cos(mlx->line_angle);
	if (!is_wall(mlx, *next_x, *next_y))
	{
		mlx->x_player = *next_x;
		mlx->y_player = *next_y;
	}
}

void	after_use_key(t_mlx *mlx)
{
	int	x_end;
	int	y_end;

	mlx_clear_window(mlx->ptr, mlx->ptr_win);
	x_end = mlx->x_player + LINE_LENGTH * cos(mlx->line_angle);
	y_end = mlx->y_player + LINE_LENGTH * sin(mlx->line_angle);
	render_map(mlx->caste_info, mlx);
	draw_line(mlx, x_end, y_end);
	mlx_put_image_to_window(mlx->ptr, mlx->ptr_win, mlx->img, 0, 0);
}
