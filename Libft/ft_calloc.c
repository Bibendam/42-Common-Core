/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:21:22 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:50:19 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*want;

	if (count > 0 && __SIZE_MAX__ / count < size)
		return (NULL);
	want = (void *)malloc(count * size);
	if (!want)
		return (NULL);
	ft_bzero(want, count * size);
	return (want);
}
/*
int	main(void) {
	size_t count = 5;
	size_t size = sizeof(int);
	int *array;

	// Allocate memory using ft_calloc
	array = (int *)ft_calloc(count, size);
	if (array == NULL) {
		printf("Memory allocation failed\n");
		return (1);
	}

	// Populate the allocated memory with some data
	for (size_t i = 0; i < count; i++) {
		array[i] = i + 1;
	}

	// Print the contents of the allocated memory
	printf("Contents of allocated memory:\n");
	for (size_t i = 0; i < count; i++) {
		printf("%d ", array[i]);
	}

	// Free the allocated memory
	free(array);

	return (0);
}*/
