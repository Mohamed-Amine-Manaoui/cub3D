/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:43:28 by wel-kass          #+#    #+#             */
/*   Updated: 2024/02/22 16:24:43 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_size(long nbr)
{
	size_t	size;

	size = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		size = 1;
	}
	if (nbr == 0)
		size = 1;
	else
	{
		while (nbr != 0)
		{
			nbr /= 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	size;
	char	*str;
	int		is_negative;

	nbr = (long)n;
	size = count_size(nbr);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	is_negative = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
		is_negative = 1;
	}
	str[size] = '\0';
	while (size > (size_t)is_negative)
	{
		str[--size] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

/*int main() {
    int numbers[] = {666, -666, 1337, 0};

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); ++i) {
        int number = numbers[i];
        char *str = ft_itoa(number);

        if (str)
            printf("Number: %d, String: %s\n", number, str);
        else
            printf("Memory allocation failed for number: %d\n", number);
    }

    return (0);
}*/
