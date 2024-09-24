/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:41:03 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/06 14:22:59 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)b;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*int main() {
    char str[] = "ALM Brotherhood";
	char strOG[] = "ALM Brotherhood";
    int value = 'K';
    size_t len = 3;

    printf("Original String: %s\n\n", str);
    printf("Filling the first %lu characters with '%c'\n\n", len, (char)value);

	memset(strOG, value, len);
	ft_memset(str, value, len);

    printf("OG: %s\n", strOG);
	printf("Memset dial talaba: %s\n", str);
    return (0);
}*/