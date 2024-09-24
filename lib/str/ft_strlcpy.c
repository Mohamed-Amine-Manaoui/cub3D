/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:33:27 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/06 22:07:04 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize)
	{
		i = 0;
		while (src[i] && dstsize - 1 > i)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

/*int main(void)
{
	char dst[4];
	const char *source = "KKK Brotherhood";

	size_t result = ft_strlcpy(dst, source, sizeof(dst));

	printf("dst: %s\n", dst);
	printf("total length: %zu\n", result);

	return (0);
}*/