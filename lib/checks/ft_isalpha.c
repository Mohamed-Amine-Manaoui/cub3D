/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:18:13 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/01 20:39:47 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

/*#int main() {
    char testChars[] = {'a', '5', 'X', '9', '$'};
    int numChars = sizeof(testChars) / sizeof(testChars[0]);

    for (int i = 0; i < numChars; i++) {
        int result = ft_isalpha(testChars[i]);
        printf("Is '%c' alpha? %s\n", testChars[i], result ? "Yes" : "No");
    }

    return (0);
}*/