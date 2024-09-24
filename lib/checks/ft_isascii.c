/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:30:19 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/01 20:24:17 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*int main() {
    char testChars[] = {'a', '5', 'X', '9', '$'};
    int numChars = sizeof(testChars) / sizeof(testChars[0]);

    for (int i = 0; i < numChars; i++) {
        int result = ft_isascii(testChars[i]);
        printf("Is '%c' ascii? %s\n", testChars[i], result ? "Yes" : "No");
    }

    return (0);
}*/