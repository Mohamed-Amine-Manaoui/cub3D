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

void ft_free(t_cub *cub)
{
	free(cub->name_file);
	free(cub->redirection_file);
	free(cub->redirection_symbol);
}

void	init_struct(t_cub *cub, char **av)
{
	cub->count = 0;
	cub->name_file = ft_strdup(av[1]);
	cub->fd = open(cub->name_file, O_RDONLY);
	if (cub->fd == -1)
		(perror(RED "open" RESET), free(cub->name_file), exit(EXIT_FAILURE));
}

// hiya li gha tgad lfuctions dial error (HHHHH)
int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
	{
		printf(RED "Sorry but this program does not accept more two arguments! (Ghyrha ^^)\n" RESET);
		exit(EXIT_FAILURE);
	}
	valid_extension(av[1]);
	// init struct
	init_struct(&cub, av);
	read_file(&cub);
	printf("count : %d\n", cub.count);
	ft_free(&cub);
	return (0);
}

// int main (int ac, char **av)
// {
// 	(void)ac;
// 	int fd = open(av[1], O_RDONLY);
// 	char *line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		if (ft_strcmp(ft_strtrim(line, "\n"), "cv") == 0)
// 		{
// 			line = get_next_line(fd);
// 			printf(RED"salammm\n"RESET);
// 			break;
// 		}
// 		line = get_next_line(fd);
// 	}
// 	while (line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
// }
