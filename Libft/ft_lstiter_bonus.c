/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:46:40 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:54:25 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int	main(void)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (1);

	node->content = malloc(100); // Assume content is 100 bytes
	if (!node->content)
	{
		free(node);
		return (1);
	}

	// Delete the node
	ft_lstiter(node, del);

	return (0);
}*/
