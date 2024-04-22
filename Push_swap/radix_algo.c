/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:46:04 by drizzo            #+#    #+#             */
/*   Updated: 2024/04/22 14:49:58 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max_bits;
	int		max;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	ra_by_count(t_list **stack_a, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
		ra(stack_a);
}

static void	pb_by_count(t_list **stack_a, t_list **stack_b, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
		pb(stack_a, stack_b);
}

static void	process_bit(t_list **stack_a, t_list **stack_b, int bit)
{
	int	j;
	int	size;
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	j = 0;
	size = ft_lstsize(*stack_a);
	while (j < size)
	{
		if ((((*stack_a)->index >> bit) & 1) == 1)
			count[0]++;
		else
			count[1]++;
		j++;
	}
	ra_by_count(stack_a, count[0]);
	pb_by_count(stack_a, stack_b, count[1]);
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}

void	radix_algo(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		process_bit(stack_a, stack_b, i);
		i++;
	}
}
