/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:13:20 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 22:13:31 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}

/*int main() {
    const char str[] = "KKK Brotherhood";
    int search_char = 'b';
    size_t n = strlen(str);

    void *result = ft_memchr(str, search_char, n);
    void *resultOG = memchr(str, search_char, n);

    if (result != NULL) {
        printf("'%c' found at position %ld\n", search_char, (char *)result
		- str);
        printf("'%c' found at position %ld\n", search_char, (char *)resultOG
		- str);
    } else {
        printf("'%c' OTHER found in the string.\n", search_char);
        printf("'%c' OTHER found in the string.\n", search_char);
    }

    return (0);
}*/