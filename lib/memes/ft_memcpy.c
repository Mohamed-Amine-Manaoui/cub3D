/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:08:14 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/06 20:57:08 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tempsrc;
	unsigned char	*tempdst;

	if (dst == src)
		return (dst);
	i = 0;
	tempsrc = (unsigned char *)src;
	tempdst = (unsigned char *)dst;
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}

// int main()
// {
//     const char *src = "KKK Brotherhood";
//     size_t len = strlen(src);

//     char dst[len];
//     char dstOG[len];
//     // int size_dst = sizeof(dst) / sizeof(dst[0]);

//     ft_memcpy(dst, src, len);
//     memcpy(dstOG, src, len);

//     printf("OG: %s\n", dstOG);
//     printf("Memcpy dial talaba: %s\n", dstOG);
// }
