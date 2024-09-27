#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_raycaste
{
	char		*no_file;
	char		*so_file;
	char		*ea_file;
	char		*we_file;
	char		*no_symbol;
	char		*so_symbol;
	char		*ea_symbol;
	char		*we_symbol;
	char		*floor;
	char		*sky;
	int			rgb_floor[3];
	int			rgb_sky[3];
}				t_raycaste;

typedef struct s_cub
{
	int			flag_floor;
	int			flag_sky;
	int			flag_no;
	int			flag_so;
	int			flag_ea;
	int			flag_we;
	int			count;
	int			fd;
	char		*name_file;
	char		*redirect_symbol;
	char		*redirect_file;
	char		*line;
	char		**rgb_;
	char		**sky;
	t_raycaste	*caste_info;
}				t_cub;

#endif