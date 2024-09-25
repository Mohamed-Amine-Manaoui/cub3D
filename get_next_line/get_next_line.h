#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	    *ft_lines(int fd, char *ptr);
char	    *ft_line(char *ptr);
char	    *ft_modulo(char *ptr);
char	    *get_next_line(int fd);

#endif
