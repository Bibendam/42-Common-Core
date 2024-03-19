/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:06:19 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:57:02 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	// Test data
	char src[] = "Hello, world!";
	char dest[20];

	// Copy src to dest using ft_memcpy
	ft_memcpy(dest, src, sizeof(src));

	// Print the copied string
	printf("Copied string: %s\n", dest);

	return (0);
}*/
