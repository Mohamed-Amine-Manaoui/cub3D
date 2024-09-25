#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_cub
{
	int 	count;
	int		fd;
	char	*name_file;
	char	*redirection_symbol;
	char	*redirection_file;
	char 	*line;
}			t_cub;

#endif