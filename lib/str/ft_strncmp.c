/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:46:46 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 23:46:48 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0 && *s1 && *s2 && *s1 == *s2)
	{
		n--;
		s1++;
		s2++;
	}
	if (n == 0 || (!*s1 && !*s2))
		return (0);
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

/*int main(void)
{
    const char *str1 = "KKK Brotherhood";
    const char *str2 = "KKK Brotherhood";
    size_t n = 5;

    int resultOG = strncmp(str1, str2, n);
    int result = ft_strncmp(str1, str2, n);

    if (result == 0 && resultOG == 0)
        printf("the strings are equal.\n", n);
    else if (result < 0 && resultOG < 0)
        printf("'%s' is lexicographically smaller than '%s'.\n", str1, str2);
    else
        printf("'%s' is lexicographically larger '%s'.\n", str1, str2);

    return (0);
}*/