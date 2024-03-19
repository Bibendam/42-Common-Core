/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:36:34 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 12:00:19 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_n;
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	len_n = ft_strlen(little);
	if (len_n == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i <= len - len_n)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j])
			j++;
		if (j == len_n)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void) {
	char *big = "Hello, world!";
	char *little = "world";
	size_t len = 13;

	printf(strnstr(big, little, len) ? "\"%s\" at %ld in \"%s\".\n" :
	"No \"%s\" in \"%s\".\n", little, strnstr(big, little, len) - big, big);

	return (0);
}*/
