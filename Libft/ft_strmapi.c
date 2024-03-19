/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:09:36 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 12:00:09 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	if (!s || !f)
		return (NULL);
	new = ft_strdup(s);
	if (!new)
		return (NULL);
	i = 0;
	while (new[i])
	{
		new[i] = (*f)(i, new[i]);
		i++;
	}
	return (new);
}
/*
static char	map_function(unsigned int index, char c) {
	if (index % 2 == 0) {
		// Capitalize even indexed characters
		if (c >= 'a' && c <= 'z')
			return (c - 'a' + 'A');
	} else {
		// Lowercase odd indexed characters
		if (c >= 'A' && c <= 'Z')
			return (c - 'A' + 'a');
	}
	return (c);
}

int	main(void) {
	// Test string
	char *test_string = "HelloWorld123";

	// Apply mapping function to the test string
	char *mapped_string = ft_strmapi(test_string, map_function);

	if (mapped_string) {
		printf("Original string: %s\n", test_string);
		printf("Mapped string: %s\n", mapped_string);

		// Free the dynamically allocated memory
		free(mapped_string);
	} else {
		printf("Memory allocation failed.\n");
	}

	return (0);
}*/
