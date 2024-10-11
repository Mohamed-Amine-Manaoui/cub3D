#ifndef STRUCTURES_H
# define STRUCTURES_H

# define SQUARE_SIZE 48
#define KeyPress 2
#define KeyPressMask (1L << 0)
# define A 97
# define D 100
# define S 115
# define W 119
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define LINE_LENGTH 40
# define SPEED 3.0

	// line_length = 40;
	// speed = 3.0;

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
	double			x_player;
	double			y_player;
	int 		player_x_pos;
	int 		player_y_pos;
	double 		angle;
	double 		line_angle;
	//
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	//draw line
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e2;
	int	err;
	t_raycaste	*caste_info;
	t_cub 		*cub_info;
}				t_mlx;


#endif
