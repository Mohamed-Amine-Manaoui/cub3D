/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:41:00 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/17 18:45:05 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

/*int main()
{
    t_list *node00;
    node00 = ft_lstnew((char *)"KKK Brotherhood!");
    t_list *node01;
    node01 = ft_lstnew((char *)"ALM Brotherhood!");
    node00->next = node01;

    printf("%s", (char *)ft_lstlast(node00)->content);
}*/