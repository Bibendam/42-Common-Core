/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:44:10 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:54:30 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*last;

	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	if (!node1 || !node2)
		return (1);
	node1->content = "Hello";
	node1->next = node2;
	node2->content = "World";
	node2->next = NULL;
	// Get the last node in the list
	last = ft_lstlast(node1);
	if (last)
		printf("Last node content: %s\n", (char *)last->content);
	// Free the nodes
	free(node1);
	free(node2);
	return (0);
}
*/
