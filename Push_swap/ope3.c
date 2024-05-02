/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:07:50 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 13:13:09 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(Node **a)
{
	rotate(a);
	ft_putendl_fd("ra\n", 1);
}

void	rb(Node **b)
{
	rotate(b);
	ft_putendl_fd("rb\n", 1);
}

void	rr(Node **a, Node **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr\n", 1);
}
