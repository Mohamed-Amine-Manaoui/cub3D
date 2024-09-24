/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:46:29 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 23:46:32 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new = ft_strdup(s);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}

/*char map_function(unsigned int index, char c) {
    if(c == 'A')
        return (c + 10);
    if(c == 'L')
        return (c - 1);
    if(c == 'M')
        return (c - 2);
}

int	main(void) {
    const char *str = "ALM";
    
    char *mapped_str = ft_strmapi(str, &map_function);

    printf("OG: %s\n", str);
    printf("output  : %s\n", mapped_str);

    return (0);
}*/