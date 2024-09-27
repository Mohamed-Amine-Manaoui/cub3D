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
void	ft_free_symbol(t_cub *cub);
#endif
