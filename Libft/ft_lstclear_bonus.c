/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:45:57 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:51:59 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
/*
void	free_content(void *content) {
	free(content);
}

int	main(void) {
	t_list *list = NULL;
	t_list *new1 = ft_lstnew("First element");
	t_list *new2 = ft_lstnew("Second element");
	t_list *new3 = ft_lstnew("Third element");

	// Add elements to the list
	ft_lstadd_back(&list, new1);
	ft_lstadd_back(&list, new2);
	ft_lstadd_back(&list, new3);

	// Clear the list
	ft_lstclear(&list, &free_content);

	// Verify that the list is cleared (list should be NULL)
	if (list == NULL) {
		printf("List is cleared successfully.\n");
	} else {
		printf("List is not cleared.\n");
	}

	return (0);
}*/
