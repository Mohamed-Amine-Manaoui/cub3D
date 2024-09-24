/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:46:01 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 23:46:04 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 > SIZE_MAX - len_s2 - 1)
		return (NULL);
	new = malloc(len_s1 + len_s2 + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len_s1);
	ft_memcpy(new + len_s1, s2, len_s2);
	new[len_s1 + len_s2] = '\0';
	return (new);
}

/*int main(void)
{
    const char *str1 = "KKK ";
    const char *str2 = "x ALM";
    
    char *joined_str = ft_strjoin(str1, str2);

    if (joined_str)
    {
        printf("pen: %s\n", str1);
        printf("apple: %s\n", str2);
        printf("apple-pen: %s\n", joined_str);
    }
    else
        printf("Memory allocation failed.\n");

    return (0);
}*/