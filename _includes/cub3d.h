#ifndef CUB3D_H
# define CUB3D_H

# include "libraries.h"
# define RED "\033[1;31m"
# define RESET "\033[0m"

void	valid_extension(char *s);
void	xpm_extension(char *s, t_cub *cub);
void	ft_free(t_cub *cub);

void	skip_whitespaces(t_cub *cub, char *str);
void	check_current_line(t_cub *cub);
void	read_file(t_cub *cub);
#endif
