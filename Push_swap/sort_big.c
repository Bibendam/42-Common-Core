/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:06:44 by drizzo            #+#    #+#             */
/*   Updated: 2024/06/18 15:49:46 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max_value;
	int	max_bits;

	max_value = 0;
	max_bits = 0;
	while (stack)
	{
		if (stack->index > max_value)
			max_value = stack->index;
		stack = stack->next;
	}
	while (max_value)
	{
		max_value >>= 1;
		max_bits++;
	}
	return (max_bits);
}

static void	push_all_to_b(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	stack_size;
	int	i;

	stack_size = get_stack_size(*stack_a);
	i = 0;
	while (i < stack_size)
	{
		if (((*stack_a)->index >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
}

static void	push_all_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	i;

	stack_size = get_stack_size(*stack_b);
	i = 0;
	while (i < stack_size)
	{
		pa(stack_a, stack_b);
		i++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	bit;

	max_bits = get_max_bits(*stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		push_all_to_b(stack_a, stack_b, bit);
		push_all_to_a(stack_a, stack_b);
		bit++;
	}
}
