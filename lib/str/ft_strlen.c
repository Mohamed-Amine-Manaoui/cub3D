/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/10/31 21:36:45 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/06 22:29:45 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/*int main() {
	const char *str1 = "KKK Brotherhood";
	const char *str2 = "";
	const char *str3 = "1337";

	size_t len1 = ft_strlen(str1);
	size_t len2 = ft_strlen(str2);
	size_t len3 = ft_strlen(str3);

	printf("Length of \"%s\" is %zu\n", str1, len1);
	printf("Length of \"%s\" is %zu\n", str2, len2);
	printf("Length of \"%s\" is %zu\n", str3, len3);

	return (0);
}*/