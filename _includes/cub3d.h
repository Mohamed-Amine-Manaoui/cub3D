#ifndef CUB3D_H
# define CUB3D_H

# include "libraries.h"
# define RED "\033[1;31m"
# define RESET "\033[0m"

char	**exec_split(char *str, char *charset);
//init struct
void    init_cub(t_cub *cub, char **av);
void	init_caste(t_raycaste *caste);
void	init_structs(t_cub *cub, t_raycaste *caste, t_mlx *mlx, char **av);
// utils
int		check_alpha(char *av);
int		handle_error(char *str);
char	**handle_whitespaces(char **av);
char	**duplicate_string(char **map);
int		is_wall(t_mlx *mlx, double next_x, double next_y);
// _free
void	ft_free(t_cub *cub);
void	free_split(char **split);
void	ft_free_symbol(t_cub *cub);
void	free_caste_struct(t_raycaste *caste);
// check extension
void	valid_extension(char *s);
void	xpm_extension(char *s, t_cub *cub);
void	calcul_with_height(t_mlx *mlx, t_raycaste *caste);
// cub3d
// pars_symbol_rgb
int		valid_rgb(char **av);
void	check_current_line(t_cub *cub, t_raycaste *caste);
void	floor_sky(t_cub *cub);
void	store_rgb(int *tab, t_cub *cub, int *flag);
void	store_symbol(char **symbol, char **file, t_cub *cub, int *flag);
// parse
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	ft_close(t_mlx *mlx);
int		is_valid_map(char **map, t_cub *cub);
void	process_file_lines(t_cub *cub, t_raycaste *caste);
void	read_file(t_cub *cub, t_raycaste *caste);
// read file
int		trim_decale(char **map, int i, int j);
void	process_header_lines(t_cub *cub, t_raycaste *caste);
void	read_map(t_cub *cub, t_raycaste *caste);
void	validate_map(char **clone_map, t_cub *cub, t_raycaste *caste);
void	check_map_presence(t_cub *cub, t_raycaste *caste);
// resize map
int		find_start(char **map);
int		find_end(char **map, int start);
void	resize_map(char **map, t_cub *cub);
// skip whitespaces
char	symbolic_character(char c);
void	check_symbol_file(char **tmp, char **check);
void	skip_whitespaces(t_cub *cub, char *str);

// valid map
int		check_first_last_line(char *first_line);
int		last_catch_error(char **map, t_cub *cub);
int		any_empty_line(char **map);
int		decalage_line(char **map);
int		valid_character_map(char *map, int *flag, t_cub *cub);
// draw map
void	draw_line(t_mlx *mlx, int x2, int y2);
void	draw_cercle(t_mlx *mlx, int Xp, int Yp, int radius);
void	paint_square(t_mlx *mlx, int col, int row, char c);
void	paint_map(t_raycaste *caste, t_mlx *mlx);
// render map
void	render_paint_square(t_mlx *mlx, int col, int row, char c);
void	render_map(t_raycaste *caste, t_mlx *mlx);
// main project
int		is_wall(t_mlx *mlx, double next_x, double next_y);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
// all keys
void	key_w(t_mlx *mlx, double *next_x, double *next_y);
void	key_s(t_mlx *mlx, double *next_x, double *next_y);
void	key_d(t_mlx *mlx, double *next_x, double *next_y);
void	key_a(t_mlx *mlx, double *next_x, double *next_y);
void	after_use_key(t_mlx *mlx);
#endif
