/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:36:57 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 15:52:02 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Node	*newNode(int value)
{
	Node	*node;

	node = malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

Node	*addNode(Node *head, int value)
{
	Node	*node;

	node = newNode(value);
	node->next = head;
	return (node);
}

void	ft_lstadd_back(Node **lst, Node *new)
{
	Node	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
			new->next = NULL;
		}
		else
		{
			*lst = new;
			new->next = NULL;
		}
	}
}

Node	*ft_lstlast(Node *head)
{
	Node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

Node	*lastNode(Node *root)
{
	while (root && root->next)
		root = root->next;
	return (root);
}
