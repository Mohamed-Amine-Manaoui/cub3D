#ifndef CUB3D_H
# define CUB3D_H

# include "libraries.h"
# define RED "\033[1;31m"
# define RESET "\033[0m"

void	valid_extension(char *s);
void	xpm_extension(char *s, t_cub *cub);
void	ft_free(t_cub *cub);

void	skip_whitespaces(t_cub *cub, char *str);
void	check_current_line(t_cub *cub, t_raycaste *caste);
void	read_file(t_cub *cub, t_raycaste *caste);
char	**exec_split(char *str, char *charset);
int		valid_rgb(char **av);
void	free_split(char **split);
void	free_caste_struct(t_raycaste *caste);
void	ft_free_symbol(t_cub *cub);
int		check_alpha(char *av);
int		handle_error(char *str);
char	**handle_whitespaces(char **av);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	floor_sky(t_cub *cub);
void	store_rgb(int *tab, t_cub *cub, int *flag);
void	store_symbol(char **symbol, char **file, t_cub *cub, int *flag);
void	skip_whitespaces(t_cub *cub, char *str);
void	check_symbol_file(char **tmp, char **check);
char	**duplicate_string(char **map);
int	    check_first_last_line(char *first_line);
int	    trim_decale(char **map, int i, int j);
// valid map
int	    last_catch_error(char **map, t_cub *cub);
int	    any_empty_line(char **map);
int	    decalage_line(char **map);
int	    valid_character_map(char *map, int *flag, t_cub *cub);
int	    is_valid_map(char **map, t_cub *cub);
// read file
void	process_header_lines(t_cub *cub, t_raycaste *caste);
void	read_map(t_cub *cub, t_raycaste *caste);
void	validate_map(char **clone_map, t_cub *cub, t_raycaste *caste);
void	check_map_presence(t_cub *cub, t_raycaste *caste);
void	process_file_lines(t_cub *cub, t_raycaste *caste);
// resize map
int	    find_start(char **map);
int	    find_end(char **map, int start);
void	resize_map(char **map, t_cub *cub);
#endif
