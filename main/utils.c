#include "../_includes/cub3d.h"

int	check_alpha(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!av[i])
		return (1);
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	handle_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == 32)
			i++;
		if (((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= 48 && str[i
					+ 1] <= 57)) || check_alpha(str))
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

char	**handle_whitespaces(char **av)
{
	int		i;
	int		j;
	char	**tmp;
	int		count;

	count = 0;
	while (av[count])
		count++;
	tmp = malloc(sizeof(char *) * (count + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == 32 || av[i][j] == 9)
			j++;
		tmp[i] = ft_strdup(av[i] + j);
		j = ft_strlen(tmp[i]) - 1;
		while (j >= 0 && (tmp[i][j] == 32 || tmp[i][j] == 9))
			j--;
		tmp[i][j + 1] = '\0';
		i++;
	}
	return (tmp[i] = NULL, tmp);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
		return (free(ptr), NULL);
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

