/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:27:21 by drizzo            #+#    #+#             */
/*   Updated: 2024/04/15 15:38:07 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **stack, int value)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != value)
			min = head->index;
	}
	return (min);
}

void	sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c)
		ra(stack_a);
	else if (a < b && a > c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c)
		rra(stack_a);
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	if (is_sorted(*stack_a))
		return ;
	dist = get_dist(stack_a, get_min(stack_a, -1));
	if (dist == 1)
		ra(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	dist = get_dist(stack_a, get_min(stack_a, -1));
	if (dist == 1)
		ra(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (dist == 4)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(*stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
