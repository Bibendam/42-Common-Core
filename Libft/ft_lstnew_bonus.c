/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:41:02 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:55:10 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	// Create a new node with content "Hello"
	t_list *node = ft_lstnew("Hello");
	if (!node)
		return (1);

	// Print the content of the node
	printf("%s\n", (char *)node->content);

	// Free the node
	free(node);

	return (0);
}*/
