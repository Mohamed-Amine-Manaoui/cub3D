/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:53:43 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/01 20:39:34 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

/*int main() {
    char testChars[] = {'a', '5', 'X', '9', '$'};
    int numChars = sizeof(testChars) / sizeof(testChars[0]);

    for (int i = 0; i < numChars; i++) {
        int result = ft_isdigit(testChars[i]);
        printf("Is '%c' a digit? %s\n", testChars[i], result ? "Yes" : "No");
    }

    return (0);
}*/