/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:59:07 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 15:51:52 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(Stack **stack, int argc, char **argv)
{
	int		i;
	Node	*new;
	char	**args;
	int		num;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (num == 0 && args[i][0] != '0')
			ft_error("Error\n");
		new = newNode(num);
		push(*stack, new);
		i++;
	}
	index_stack(&((*stack)->top));
	if (argc == 2)
		ft_free(args);
}

int	stack_size(Stack *stack)
{
	int		size;
	Node	*node;

	size = 0;
	node = stack->top;
	while (node != NULL)
	{
		size++;
		node = node->prev;
	}
	return (size);
}

void	sort_stack(Stack **stack_a, Stack **stack_b)
{
	Stack	*temp_stack_b;

	temp_stack_b = NULL;
	if (!(*stack_b))
	{
		temp_stack_b = create_empty_stack();
		*stack_b = temp_stack_b;
	}
	quicksort(*stack_a, *stack_b, 0, stack_size(*stack_a) - 1);
	if (temp_stack_b)
	{
		free_stack(&temp_stack_b->top);
		free(temp_stack_b);
	}
}

void	print_stack(Node *top)
{
	Node	*node;

	node = top;
	while (node != NULL)
	{
		printf("%d ", node->value);
		node = node->prev;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	Stack	*stack_a;

	stack_a = newStack();
	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	init_stack(&stack_a, argc, argv);
	if (!is_sorted(stack_a->top))
	{
		sort_stack(&stack_a, NULL);
	}
	printf("Sorted stack: \n");
	print_stack(stack_a->top);
	free_stack(&stack_a->top);
	free(stack_a);
	return (0);
}
