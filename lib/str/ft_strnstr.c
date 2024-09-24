/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:12:24 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 22:12:30 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	littlen;
	size_t	i;
	size_t	j;

	if (!big && len == 0)
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	littlen = ft_strlen(little);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (j == littlen)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

int	ft_strnstr_int(const char *big, const char *little, size_t len)
{
	size_t	littlen;
	size_t	i;
	size_t	j;

	if (!big && len == 0)
		return (1);
	if (ft_strlen(little) == 0)
		return (0);
	littlen = ft_strlen(little);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (j == littlen)
			return (0);
		i++;
	}
	return (1);
}

/*int main() {
    const char *haystack = "Hello, KKK!";
    const char *needle = "KKK";
    size_t len = 13; 

    char *result = ft_strnstr(haystack, needle, len);

    if (result != NULL) {
        printf("found at position %ld: %s\n", result - haystack, result);
    } else {
        printf("OTHER found!\n");
    }

    return (0);
}*/