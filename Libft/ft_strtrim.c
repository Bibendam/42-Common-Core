/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:51:11 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 12:00:50 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!set || !s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && char_set(s1[start], set))
		start++;
	while (end > start && char_set(s1[end - 1], set))
		end--;
	len = end - start;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, len + 1);
	return (str);
}
/*
int	main(void) {
	char const *s1 = "  \t  Hello, world!   \t  ";
	char const *set = " \t";

	char *trimmed = ft_strtrim(s1, set);
	if (trimmed) {
		printf("Original string: \"%s\"\n", s1);
		printf("Trimmed string: \"%s\"\n", trimmed);
		free(trimmed); // Don't forget to free the allocated memory
	} else {
		printf("Failed to trim the string.\n");
	}

	return (0);
}*/
