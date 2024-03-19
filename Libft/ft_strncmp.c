/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:27:02 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 12:00:14 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char *s1 = "t";
	char *s2 = "";
	unsigned int n = 0;

	// Compare the strings using ft_strncmp
	int result = ft_strncmp(s1, s2, n);

	// Print the result
	if (result == 0)
		printf("Strings are equal up to %u characters.\n", n);
	else if (result < 0)
		printf("String s1 is less than string s2.\n");
	else
		printf("String s1 is greater than string s2.\n");

	return (0);
}*/
