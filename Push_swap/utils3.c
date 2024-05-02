/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:20:57 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 15:51:56 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack	*create_empty_stack(void)
{
	Stack	*new_stack;

	new_stack = (Stack *)malloc(sizeof(Stack));
	if (new_stack == NULL)
		ft_error("Error\n");
	new_stack->top = NULL;
	return (new_stack);
}

static int	index_of(Node **sorted_stack, int value)
{
	Node	*current;
	int		index;

	current = *sorted_stack;
	index = 0;
	while (current)
	{
		if (current->value == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

static Stack	*sort_single_stack(Stack **stack)
{
	Stack	*stack_b;

	stack_b = create_empty_stack();
	sort_stack(stack, &stack_b);
	free(stack_b);
	return (*stack);
}

void	index_stack(Node **stack)
{
	Node	*head;
	Stack	*sorted_stack;
	Stack	*temp_stack;

	temp_stack = create_empty_stack();
	temp_stack->top = *stack;
	sorted_stack = sort_single_stack(&temp_stack);
	head = (*stack);
	while (head)
	{
		head->index = index_of(&(sorted_stack->top), head->value);
		head = head->next;
	}
	free(temp_stack);
}
