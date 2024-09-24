/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:09:26 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/16 22:09:35 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

/*int main() {
  t_list *head = ft_lstnew("KKK Brotherhood!");

  printf("%s\n", (char *)head->content);
  
  head->content = (char *)"123";
  printf("%s\n", (char *)head->content);
  return (0);
}*/