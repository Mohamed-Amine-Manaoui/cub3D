/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:55:32 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/01 20:56:44 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*#include<stdio.h>
int	main(void) {
    char line = 'W';
    char result = ft_tolower(line);

    printf("Original character: %c\n", line);
    printf("Lowercase character: %c\n", result);

    return (0);
}*/