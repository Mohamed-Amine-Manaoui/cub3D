/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:42:46 by wel-kass          #+#    #+#             */
/*   Updated: 2024/09/24 23:58:05 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

/*int main(void)
{
	char str[] = "KKK Brotherhood";
	char c = 'B';
	printf("OG : %s\n", strchr(str, c));
	printf("Strchr d talaba : %s\n", ft_strchr(str, c));
	return (0);
}*/