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
	// read_map
	int			row;
	int			cols;
	char		*trimmed_line;
	char		**map;
}				t_raycaste;

typedef struct s_cub
{
	int			flag_p;
	int			flag_no;
	int			flag_so;
	int			flag_ea;
	int			flag_we;
	int			flag_sky;
	int			flag_floor;
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

typedef struct s_mlx
{
	void		*ptr;
	void		*ptr_win;
	size_t		w_h_map[2];
	int			x_player;
	int			y_player;
}				t_mlx;

#endif