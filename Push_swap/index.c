/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:13:21 by drizzo            #+#    #+#             */
/*   Updated: 2024/06/26 15:40:15 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_tokens(char *arg, t_stack **stack_a)
{
	char		**tokens;
	long int	nb;
	int			j;

	j = 0;
	tokens = ft_split(arg, ' ');
	while (tokens[j] != NULL)
	{
		nb = ft_atoi(tokens[j]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(stack_a, NULL);
		if (*stack_a == NULL)
			*stack_a = stack_new((int)nb);
		else
			stack_add_bottom(stack_a, stack_new((int)nb));
		free(tokens[j]);
		j++;
	}
	free(tokens);
}

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		handle_tokens(av[i], &stack_a);
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
