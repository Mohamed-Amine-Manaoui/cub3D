/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:47:09 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/24 04:56:05 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

// static int	isset(char c, const char *set);
// static char	*fstr(const char *begin, const char *end);

// char	*ft_strtrim(const char *s1, const char *set)
// {
// 	unsigned int	i;
// 	size_t			end;
// 	char			*result;

// 	if (!s1 || !set)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] && isset(s1[i], set))
// 		i++;
// 	end = i;
// 	while (s1[end])
// 		end++;
// 	while (end > i && isset(s1[end - 1], set))
// 		end--;
// 	result = fstr(s1 + i, s1 + end - 1);
// 	return (result);
// }

// static int	isset(char c, const char *set)
// {
// 	while (*set)
// 	{
// 		if (*set == c)
// 			return (1);
// 		set++;
// 	}
// 	return (0);
// }

// static char	*fstr(const char *begin, const char *end)
// {
// 	char			*new;
// 	unsigned int	i;

// 	new = malloc(sizeof(char) * (end - begin + 2));
// 	if (!new)
// 		return (NULL);
// 	i = 0;
// 	while (begin + i <= end)
// 	{
// 		new[i] = begin[i];
// 		i++;
// 	}
// 	new[i] = '\0';
// 	return (new);
// }

/*int	main(void)
{
	const char	*str;
	const char	*set;
	char		*trimmed_str;

	str = " KKKALM Brotherhood!KKK";
	set = "K";
	trimmed_str = ft_strtrim(str, set);
	if (trimmed_str != NULL)
	{
		printf("OG: \"%s\"\n", str);
		printf("trimmed: \"%s\"\n", trimmed_str);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}*/


char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	i = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[i]) && i != 0)
		i--;
	return (ft_substr((char *)s1, 0, i + 1));
}
// int main ()
// {
//     char s1[] = "1234Mohamed Amine";
//     char set[] = "123";
//     char *str = ft_strtrim(s1, set);
//     printf("%s",str);
// }