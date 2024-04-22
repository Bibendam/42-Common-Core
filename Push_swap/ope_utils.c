/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:07:23 by drizzo            #+#    #+#             */
/*   Updated: 2024/04/19 15:51:06 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return (-1);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	return (0);
}

int	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b)
		return (-1);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return (-1);
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_to_last;

	if (!*stack || !(*stack)->next)
		return (-1);
	last = *stack;
	second_to_last = NULL;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}
