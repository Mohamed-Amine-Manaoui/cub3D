#include "../_includes/cub3d.h"

void	valid_extension(char *s)
{
	char	*extension;

	extension = ft_strrchr(s, '.');
	if (!extension)
	{
		printf(RED "Invalid File (Ghyrha ^^)\n" RESET);
		exit(1);
	}
	if (ft_strcmp(extension, ".cub"))
	{
		printf(RED "Invalid extension (Ghyrha ^^)\n" RESET);
		exit(1);
	}
}

void	xpm_extension(char *s, t_cub *cub)
{
	char	*extension;

	extension = ft_strrchr(s, '.');
	if (!extension)
	{
		printf(RED " %s : invalid xpm file (Ghyrha ^^)\n" RESET,
			cub->redirection_file);
		free(cub->line);
		ft_free(cub);
		exit(1);
	}
	if (ft_strcmp(extension, ".xpm"))
	{
		printf(RED "%s : Invalid xpm extension (Ghyrha ^^)\n" RESET,
			cub->redirection_file);
		free(cub->line);
		ft_free(cub);
		exit(1);
	}
}
