/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:03:07 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/01 11:57:07 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*#include <stdio.h>
int	main(void) {
    char testChars[] = {'a', '5', 'X', '9', '$'};
    int numChars = sizeof(testChars) / sizeof(testChars[0]);

    for (int i = 0; i < numChars; i++) {
        int result = ft_isalnum(testChars[i]);
        printf("Is '%c' alnum? %s\n", testChars[i], result ? "Yes" : "No");
    }

    return (0);
}*/