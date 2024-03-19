/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:30:23 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 12:00:25 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}
/*
int	main(void) {
	const char *s = "Hello, world!";
	int c = 'o';

	// Search for the last occurrence of character 'o' in the string
	char *result = ft_strrchr(s, c);

	// Print the result
	if (result != NULL)
		printf(result ? "Last '%c' at %ld.\n" : "No '%c'.\n", c, result - s);
	else
		printf("Character '%c' not found in \"%s\".\n", c, s);

	return (0);
}*/
