/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:39:49 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:59:39 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}
/*
int	main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "world!";

	// Concatenate the strings using ft_strjoin
	char *result = ft_strjoin(s1, s2);

	if (result)
	{
		// Print the concatenated string
		printf("Concatenated string: %s\n", result);

		// Free the memory allocated for the result string
		free(result);
	}
	else
	{
		printf("Failed to concatenate the strings.\n");
	}

	return (0);
}*/
