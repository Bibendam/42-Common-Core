/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:27:21 by drizzo            #+#    #+#             */
/*   Updated: 2024/04/22 14:39:45 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_index(t_list **stack)
{
	t_list	*head;
	int		min;
	int		min_index;
	int		i;

	head = *stack;
	min = head->value;
	min_index = 0;
	i = 0;
	while (head)
	{
		if (head->value < min)
		{
			min = head->value;
			min_index = i;
		}
		head = head->next;
		i++;
	}
	return (min_index);
}

void	sort_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first > second && second < third)
		sa(stack_a);
	else if (first < second && second > third && first < third)
		sa(stack_a);
	else if (first < second && second > third)
		rra(stack_a);
	else if (first > third)
		ra(stack_a);
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = get_min_index(stack_a);
	while (min_index--)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	while (get_min_index(stack_a) != 0)
		ra(stack_a);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = get_min_index(stack_a);
	while (min_index--)
		ra(stack_a);
	pb(stack_a, stack_b);
	min_index = get_min_index(stack_a);
	while (min_index--)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	while (get_min_index(stack_a) != 0)
		ra(stack_a);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		quicksort(stack_a, 0, size - 1);
}
