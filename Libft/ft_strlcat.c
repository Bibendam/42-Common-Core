/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:50:42 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:59:49 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	total_len;
	size_t	index;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	total_len = len_dst + len_src;
	index = len_dst;
	if (size <= len_dst)
		return (len_src + size);
	i = 0;
	while (src[i] != '\0' && index < size - 1)
	{
		dst[index++] = src[i++];
	}
	dst[index] = '\0';
	return (total_len);
}
/*
int	main(void) {
	char dst[20] = "Hello ";
	const char *src = "world";
	size_t size = sizeof(dst);

	printf("Before strlcat:\n");
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);

	size_t result = ft_strlcat(dst, src, size);

	printf("\nAfter strlcat:\n");
	printf("dst: %s\n", dst);
	printf("Result: %zu\n", result);

	return (0);
}*/
