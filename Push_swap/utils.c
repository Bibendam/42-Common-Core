/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:00:53 by drizzo            #+#    #+#             */
/*   Updated: 2024/04/15 15:37:30 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

int	is_sorted(t_list *stack)
{
	t_list	*head;

	head = stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_dist(t_list **stack, int index)
{
	t_list	*head;
	int		dist;

	head = *stack;
	dist = 0;
	while (head)
	{
		if (head->index == index)
			break ;
		dist++;
		head = head->next;
	}
	return (dist);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp != NULL)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	*stack = NULL;
}
