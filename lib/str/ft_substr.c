/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:47:28 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 23:47:35 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*new;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (NULL);
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	count = 0;
	while (count < len)
	{
		new[count] = s[start + count];
		count++;
	}
	new[count] = '\0';
	return (new);
}

/*int main(void)
{
    const char *original = "KKK x ALM? Brotherhood!";
    unsigned int start = 11;
    size_t length = 13;

    char *substring = ft_substr(original, start, length);

    if (substring)
    {
        printf("Original: %s\n", original);
        printf("Substring: %s\n", substring);
    }
    else
        printf("Memory allocation failed.\n");

    return (0);
}*/
