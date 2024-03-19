/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:11:02 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:59:01 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
	{
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
/*
int	main(void)
{
	const char *s = "Hello, world!";
	int c = 'o';

	// Find the first occurrence of character 'o' in the string
	char *result = ft_strchr(s, c);

	if (result)
	{
		printf("Character '%c' found at position: %ld\n", c, result - s);
	}
	else
	{
		printf("Character '%c' not found\n", c);
	}

	return (0);
}*/
