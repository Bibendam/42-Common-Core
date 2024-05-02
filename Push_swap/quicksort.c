/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:27:21 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 15:53:09 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack	*newStack(void)
{
	Stack	*stack;

	stack = (Stack *)malloc(sizeof(Stack));
	stack->top = NULL;
	return (stack);
}

static int	partition(Stack *stack, Stack *helper, int low, int high)
{
	int		pivot;
	Node	*node;
	int		i;

	pivot = stack->top->value;
	node = stack->top->next;
	i = low;
	for (int j = low; j <= high; j++)
	{
		if (!node)
		{
			break ;
		}
		if (node->value < pivot)
		{
			i++;
			push(helper, pop(stack));
		}
		else
		{
			push(stack, pop(stack));
		}
		node = node->next;
	}
	while (helper->top)
	{
		push(stack, pop(helper));
	}
	return (i);
}

void	quicksort(Stack *stack, Stack *helper, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(stack, helper, low, high);
		quicksort(stack, helper, low, pi - 1);
		quicksort(stack, helper, pi + 1, high);
	}
}
