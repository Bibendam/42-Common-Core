/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:01 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:50:11 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}
/*
int	main(void) {
	char array[] = "Hello, world!";
	size_t size = sizeof(array);

	printf("Before ft_bzero: %s\n", array);

	// Call ft_bzero to zero out the array
	ft_bzero(array, size);

	printf("After ft_bzero: %s\n", array);

	return (0);
}*/
