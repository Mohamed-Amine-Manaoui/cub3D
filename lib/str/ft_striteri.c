/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:45:41 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 23:45:45 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void uppercaseChar(unsigned int index, char *c) {
    *c = (char)ft_toupper((int)(*c));
}

int	main(void)
{
    char str[] = "kkk";

    printf("output: %s\n", str);

    ft_striteri(str, uppercaseChar);

    printf("uppercase: %s\n", str);

    return (0);
}*/