/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:43:24 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:59:54 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	char src[] = "This is a test string.";
	char dst[20];

	// Copy the source string to the destination string using ft_strlcpy
	size_t result_length = ft_strlcpy(dst, src, sizeof(dst));

	// Print the copied string and its length
	printf("Copied string: %s\n", dst);
	printf("Length of copied string: %zu\n", result_length);

	return (0);
}*/
