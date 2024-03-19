/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:52:58 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:51:51 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void) {
	t_list *list = NULL;
	t_list *new1 = ft_lstnew("First element");
	t_list *new2 = ft_lstnew("Second element");
	t_list *new3 = ft_lstnew("Third element");

	ft_lstadd_front(&list, new3);
	ft_lstadd_front(&list, new2);
	ft_lstadd_front(&list, new1);

	// Traverse the list and print its elements
	printf("List elements:\n");
	t_list *current = list;
	while (current != NULL) {
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	// Remember to free the memory allocated for the list nodes
	ft_lstclear(&list, &free);

	return (0);
}*/
