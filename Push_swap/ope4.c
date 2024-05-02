/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:07:58 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 13:13:34 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(Node **a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra\n", 1);
}

void	rrb(Node **b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb\n", 1);
}

void	rrr(Node **a, Node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr\n", 1);
}
