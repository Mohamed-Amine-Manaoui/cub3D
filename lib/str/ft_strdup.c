/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/16 22:17:52 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 22:18:05 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}

/*int main(void)
{
	const char *original = "KKK Brotherhood";

	char *duplicateOG = strdup(original);
	char *duplicate = ft_strdup(original);

	if (duplicate)
	{
		printf("OG: %s\n", duplicateOG);
		printf("Strdup dial talaba: %s\n", duplicate);
	}
	else
		printf("Memory allocation failed.\n");

	return (0);
}*/