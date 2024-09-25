#include "get_next_line.h"

char	*ft_lines(int fd, char *ptr)
{
	char	*buffer;
	char	*tmp;
	ssize_t	n_byte;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n_byte = 1;
	while (n_byte != 0 && !ft_strchr(ptr, '\n'))
	{
		n_byte = read(fd, buffer, BUFFER_SIZE);
		if (n_byte == -1)
			return (free(ptr), free(buffer), NULL);
		buffer[n_byte] = '\0';
		tmp = ptr;
		ptr = ft_strjoin(ptr, buffer);
		free(tmp);
		if (!ptr)
			return (NULL);
	}
	free(buffer);
	return (ptr);
}

char	*ft_line(char *ptr)
{
	size_t	i;
	size_t	k;
	char	*aide;

	i = 0;
	if (!ptr)
		return (NULL);
	if (ptr[0] == '\0')
		return (NULL);
	while (ptr[i] != '\n' && ptr[i])
		i++;
	if (ptr[i] == '\n')
		i++;
	aide = malloc(i + 1);
	if (!aide)
		return (NULL);
	k = 0;
	i = 0;
	while (ptr[i] != '\n' && ptr[i])
		aide[k++] = ptr[i++];
	if (ptr[i] == '\n')
		aide[k++] = '\n';
	aide[k] = '\0';
	return (aide);
}

char	*ft_modulo(char *ptr)
{
	int		i;
	int		length;
	char	*tmp;

	if (!ptr)
		return (NULL);
	length = ft_strlen(ptr);
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	else
	{
		free(ptr);
		return (NULL);
	}
	tmp = ptr;
	ptr = ft_substr(tmp, i, length);
	free(tmp);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*tab;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = ft_lines(fd, ptr);
	tab = ft_line(ptr);
	ptr = ft_modulo(ptr);
	return (tab);
}
