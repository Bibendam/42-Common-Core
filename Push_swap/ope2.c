/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:07:42 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 13:42:37 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(Stack *a, Stack *b)
{
	int	value;

	if (a == NULL || b == NULL || b->top == NULL)
		return ;
	value = pop(b);
	push(a, value);
	ft_putendl_fd("pa", 1);
}

void	pb(Stack *a, Stack *b)
{
	int	value;

	if (a == NULL || a->top == NULL)
		return ;
	value = pop(a);
	push(b, value);
	ft_putendl_fd("pb", 1);
}
