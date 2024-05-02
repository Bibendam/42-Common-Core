/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:07:23 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 15:52:57 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(Stack *stack, Node *node)
{
	if (stack == NULL)
	{
		ft_error("Error\n");
		return ;
	}
	if (node == NULL)
	{
		ft_error("Error\n");
		return ;
	}
	node->prev = stack->top;
	if (stack->top)
	{
		stack->top->next = node;
	}
	stack->top = node;
}

Node	*pop(Stack *stack)
{
	Node	*node;

	if (!stack->top)
	{
		return (NULL);
	}
	node = stack->top;
	stack->top = node->prev;
	if (stack->top)
	{
		stack->top->next = NULL;
	}
	return (node);
}

void	swap(Node **stack)
{
	Node	*first;
	Node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	rotate(Node **stack)
{
	Node	*first;
	Node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
}

void	reverse_rotate(Node **stack)
{
	Node	*last;
	Node	*prev;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	last = *stack;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}
