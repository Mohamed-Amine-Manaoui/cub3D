/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:31:48 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/06 15:07:49 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int main() 
{
    char str[] = "KKK Brotherhood";
    char strOG[] = "KKK Brotherhood";
    size_t len = 4;

    printf("Original String: %s\n", str);

    ft_bzero(str + len, len);
    bzero(strOG + len, len);

    printf("OG: %s\n", strOG);
    printf("Bzero dial talaba : %s\n", str);

    return (0);
}*/