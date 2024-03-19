/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:12 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:56:54 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/*int main(void) {
	char str[] = "Hello, world!";
	int character = 'o';
	size_t n = sizeof(str);
	void *result = memchr(str, character, n);
	printf(result ? "'%c' at %ld.\n" :
	"No '%c'.\n", character, (char *)result - str);
	return (0);
}*/
