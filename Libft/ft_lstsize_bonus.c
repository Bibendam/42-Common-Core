/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:43:07 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:55:37 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	if (!node1 || !node2)
		return (1);

	node1->content = "Hello";
	node1->next = node2;

	node2->content = "World";
	node2->next = NULL;

	// Get the size of the list
	int size = ft_lstsize(node1);
	printf("List size: %d\n", size);

	// Free the nodes
	free(node1);
	free(node2);

	return (0);
}*/
