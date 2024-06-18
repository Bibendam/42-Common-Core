/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:59:05 by drizzo            #+#    #+#             */
/*   Updated: 2024/06/18 15:59:43 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_index(t_stack *stack)
{
	int	min_index;

	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

static int	find_second_smallest_index(t_stack *stack)
{
	int	min_index;
	int	second_min_index;

	min_index = find_smallest_index(stack);
	second_min_index = INT_MAX;
	while (stack)
	{
		if (stack->index < second_min_index && stack->index != min_index)
			second_min_index = stack->index;
		stack = stack->next;
	}
	return (second_min_index);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	min1;
	int	min2;

	stack_size = get_stack_size(*stack_a);
	if (stack_size <= 3)
		sort_small(stack_a);
	else
	{
		min1 = find_smallest_index(*stack_a);
		min2 = find_second_smallest_index(*stack_a);
		while ((*stack_a)->index == min1 || (*stack_a)->index == min2)
		{
			pb(stack_a, stack_b);
			if ((*stack_a)->index == min1)
				min1 = find_smallest_index(*stack_a);
			else
				min2 = find_second_smallest_index(*stack_a);
		}
		sort_small(stack_a);
		while (get_stack_size(*stack_b) > 0)
			pa(stack_a, stack_b);
		sort_small(stack_a);
	}
}
