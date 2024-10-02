#include "../_includes/cub3d.h"

void	print_file(t_cub *cub)
{
	char	*line;

	line = get_next_line(cub->fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(cub->fd);
	}
}

void	print_map(t_raycaste *caste)
{
	size_t i = 0; while(caste->map[i] != NULL)
	{
		if (!caste->map[i])
			break;
		printf("%s\n", caste->map[i]);
	i++;
	}
}

void	init_structs(t_cub *cub, t_raycaste *caste, char **av)
{
	caste->row = 0;
	cub->count = 0;
	cub->flag_p = 0;
	cub->flag_no = 0;
	cub->flag_so = 0;
	cub->flag_ea = 0;
	cub->flag_we = 0;
	cub->flag_sky = 0;
	cub->flag_floor = 0;
	caste->map = NULL;
	caste->no_file = NULL;
	caste->so_file = NULL;
	caste->ea_file = NULL;
	caste->we_file = NULL;
	caste->no_symbol = NULL;
	caste->so_symbol = NULL;
	caste->ea_symbol = NULL;
	caste->we_symbol = NULL;
	cub->redirect_file = NULL;
	caste->trimmed_line = NULL;
	cub->redirect_symbol = NULL;
	cub->name_file = ft_strdup(av[1]);
	cub->fd = open(cub->name_file, O_RDONLY);
	if (cub->fd == -1)
		(perror(RED "open" RESET), free(cub->name_file), exit(EXIT_FAILURE));
}

// hiya li gha tgad lfuctions dial error (HHHHH)
int	main(int ac, char **av)
{
	t_cub		cub;
	t_raycaste	caste;

	if (ac != 2)
	{
		printf(RED "Sorry but this program does not accept more two arguments! (Ghyrha ^^)\n" RESET);
		exit(EXIT_FAILURE);
	}
	cub.caste_info = &caste;
	valid_extension(av[1]);
	// init struct
	init_structs(&cub, &caste, av);
	read_file(&cub, &caste);
	// printf("count : %d\n", cub.count);
	print_map(&caste);
	free_split(caste.map);
	free_caste_struct(&caste);
	ft_free(&cub);
	return (0);
}
