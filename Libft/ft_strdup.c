/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:45 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:59:26 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	int		i;

	if (src == NULL)
	{
		return (NULL);
	}
	i = 0;
	res = malloc(ft_strlen(src) + 1);
	if (!res)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
int	main(void)
{
	char *src = "Hello, world!";

	// Duplicate the string using ft_strdup
	char *duplicate = ft_strdup(src);

	if (duplicate)
	{
		// Print the duplicate string
		printf("Original string: %s\n", src);
		printf("Duplicate string: %s\n", duplicate);

		// Free the memory allocated for the duplicate string
		free(duplicate);
	}
	else
	{
		printf("Failed to duplicate the string.\n");
	}

	return (0);
}*/
