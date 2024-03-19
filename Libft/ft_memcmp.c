/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:46:24 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:56:58 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	if (i < n)
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}
/*
int	main(void)
{
	// Test data
	char str1[] = "Hello, world!";
	char str2[] = "Hello, there!";
	size_t n = 6; // Compare first 6 characters

	// Compare the strings
	int result = memcmp(str1, str2, n);

	// Print the result
	if (result < 0)
	{
		printf("str1 is less than str2\n");
	}
	else if (result > 0)
	{
		printf("str1 is greater than str2\n");
	}
	else
	{
		printf("str1 is equal to str2\n");
	}

	return (0);
}*/
