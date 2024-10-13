/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/11/04 14:13:21 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/09 23:04:19 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"


int	ft_atoi(const char *str)
{
	int s;
	long r;
	int i;

	s = 1;
	r = 0;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + str[i] - '0';
		if (r * s > INT_MAX || r * s < INT_MIN)
			exit(printf("out range for INT\n"));
		i++;
	}
	return ((int)r * s);
}

/*int main()
{
	const char *str = "		\v\t\r\n-666_++__";
	int num = atoi(str);
	int ft_num = ft_atoi(str);
	printf("OG: %d\n", num);
	printf("Atoi dial talaba:%d\n", ft_num);
	return (0);
}*/