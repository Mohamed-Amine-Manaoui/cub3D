/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:32:03 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/01 20:27:42 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*int main() {
    char testChars[] = {'a', '5', 'X', '9', '$'};
    int numChars = sizeof(testChars) / sizeof(testChars[0]);

    for (int i = 0; i < numChars; i++) {
        int result = ft_isprint(testChars[i]);
        printf("Is '%c' printable? %s\n", testChars[i], result ? "Yes" : "No");
    }

    return (0);
}*/