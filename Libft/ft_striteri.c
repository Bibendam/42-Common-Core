/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:18:43 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:59:32 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
	{
		return ;
	}
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
static void	iter_function(unsigned int index, char *c) {
	if (*c >= 'a' && *c <= 'z') {
		if (index % 2 == 0) {
			*c = *c - 'a' + 'A';
		} else {
			*c = *c - 'a' + 'a';
		}
	}
}

int	main(void) {
	// Test string
	char test_string[] = "hello world";

	// Apply iteration function to the test string
	ft_striteri(test_string, iter_function);

	printf("Modified string: %s\n", test_string);

	return (0);
}*/
