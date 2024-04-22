/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:31:31 by drizzo            #+#    #+#             */
/*   Updated: 2024/04/22 14:28:20 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swapping(t_list *a, t_list *b)
{
	t_list	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	median_of_three(t_list **stack_a, int low, int high)
{
	int	mid;

	mid = low + (high - low) / 2;
	if ((*stack_a)[low].value > (*stack_a)[mid].value)
		swapping(&(*stack_a)[low], &(*stack_a)[mid]);
	if ((*stack_a)[low].value > (*stack_a)[high].value)
		swapping(&(*stack_a)[low], &(*stack_a)[high]);
	if ((*stack_a)[mid].value > (*stack_a)[high].value)
		swapping(&(*stack_a)[mid], &(*stack_a)[high]);
	return (mid);
}

static int	partition(t_list **stack_a, int low, int high)
{
	int	pivot_index;
	int	pivot;
	int	i;
	int	j;

	pivot_index = median_of_three(stack_a, low, high);
	swapping(&(*stack_a)[pivot_index], &(*stack_a)[high]);
	pivot = (*stack_a)[high].value;
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if ((*stack_a)[j].value < pivot)
		{
			i++;
			swapping(&(*stack_a)[i], &(*stack_a)[j]);
		}
		j++;
	}
	swapping(&(*stack_a)[i + 1], &(*stack_a)[high]);
	return (i + 1);
}

void	quicksort(t_list **stack_a, int l, int h)
{
	int	*stack;
	int	top;
	int	p;

	stack = malloc((h - l + 1) * sizeof(int));
	top = -1;
	stack[++top] = l;
	stack[++top] = h;
	while (top >= 0)
	{
		h = stack[top--];
		l = stack[top--];
		p = partition(stack_a, l, h);
		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
	free(stack);
}
