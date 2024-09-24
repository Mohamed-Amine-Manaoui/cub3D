/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:16:24 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 22:16:29 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = s1;
	p2 = s2;
	i = 0;
	while (n > 0 && p1[i] == p2[i])
	{
		i++;
		n--;
	}
	if (n > 0)
		return (p1[i] - p2[i]);
	return (0);
}

/*int main(void)
{
    const char str1[] = "ALM Brotherhood";
    const char str2[] = "KKK Brotherhood";
    size_t n = 5;

    int result = ft_memcmp(str1, str2, n);
    int resultOG = memcmp(str1, str2, n);

    if (result == 0 && resultOG == 0)
        printf("The strings are equal.\n", n);
    else if (result < 0 && resultOG < 0) 
        printf("'%s' is lexicographically smaller than '%s'.\n", str1, str2);
    else if(result > 0 && resultOG > 0)
        printf("'%s' is lexicographically larger than '%s'.\n", str1, str2);

    return (0);
}*/