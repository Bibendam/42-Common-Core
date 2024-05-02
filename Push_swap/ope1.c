/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:07:34 by drizzo            #+#    #+#             */
/*   Updated: 2024/05/02 13:12:47 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(Node **a)
{
	swap(a);
	ft_putendl_fd("sa\n", 1);
}

void	sb(Node **b)
{
	swap(b);
	ft_putendl_fd("sb\n", 1);
}

void	ss(Node **a, Node **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss\n", 1);
}
