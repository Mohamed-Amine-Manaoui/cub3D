/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:30:00 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/06 20:54:55 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	if (!dst && !src)
		return (NULL);
	i = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (a > b)
	{
		while (len-- > 0)
			a[len] = b[len];
	}
	else
	{
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dst);
}

/*int main()
{
    char src[] = "KKK Brotherhood";
    size_t size = strlen(src);

    char dst[size];
    char dstOG[size];

    size_t len = 4;

    ft_memmove(dst, src, len);
    memmove(dstOG, src, len);

    printf("OG: %s\n", dstOG);
    printf("Memmove dial talaba: %s\n", dstOG);
    return (0);
}*/