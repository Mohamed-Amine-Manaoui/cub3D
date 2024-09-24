/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanaoui <mmanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:54:32 by wel-kass          #+#    #+#             */
/*   Updated: 2024/09/24 21:05:42 by mmanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_m(t_malloc **lst, t_malloc *new)
{
	t_malloc	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

t_malloc	*ft_lstnew_m(void *data)
{
	t_malloc	*ptr;

	ptr = malloc(sizeof(t_malloc));
	if (ptr == NULL)
		return (NULL);
	ptr->data = data;
	ptr->next = NULL;
	return (ptr);
}

void	*ft_malloc(size_t size, char f_or_m)
{
	void			*ptr;
	static t_malloc	*head;
	t_malloc		*tmp;

	if (f_or_m == 'f')
	{
		while (head)
		{
			tmp = head->next;
			free(head->data);
			free(head);
			head = tmp;
		}
		head = NULL;
		return (NULL);
	}
	ptr = malloc(size);
	ft_lstadd_back_m(&head, ft_lstnew_m(ptr));
	return (ptr);
}

// int main ()
// {
//     char *str;
//     str = malloc(10);
//     malloc(0, 'f');
//     return (0);
// }