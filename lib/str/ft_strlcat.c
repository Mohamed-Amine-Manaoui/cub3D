/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:34:24 by wel-kass          #+#    #+#             */
/*   Updated: 2024/02/22 16:26:15 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	if (!dst && size == 0)
		return (srclen);
	while (dst[i] && i < size)
		i++;
	destlen = i;
	if (size <= destlen)
		return (size + srclen);
	j = 0;
	while (i < size - 1 && src[j])
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (destlen + srclen);
}
