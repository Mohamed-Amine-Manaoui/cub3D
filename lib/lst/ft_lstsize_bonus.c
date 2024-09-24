/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:19:48 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/17 18:20:20 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*int main(){
    t_list *node00;
    t_list *node01;
    t_list *node02;
    node00 = ft_lstnew((char *)"KKK Brotherhood!");
    node01 = ft_lstnew((char *)"ALM Brotherhood!");

    node00 -> next = node01;

    node02 = ft_lstnew((char *)"Peace Brotherhood!");

    node01 -> next = node02;
    printf("%d", ft_lstsize(node00));
    return (0);
}*/