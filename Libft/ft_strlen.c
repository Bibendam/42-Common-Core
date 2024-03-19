/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:34:08 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 12:00:04 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char *s = "Hello, world!";

	// Calculate the length of the string using ft_strlen
	size_t length = ft_strlen(s);

	// Print the length of the string
	printf("Length of the string \"%s\": %zu\n", s, length);

	return (0);
}*/
