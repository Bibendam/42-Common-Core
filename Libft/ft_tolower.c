/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:06:50 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 12:01:09 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int num)
{
	if (num >= 'A' && num <= 'Z')
		return (num += 32);
	return (num);
}
/*
int	main(void) {
	int c;

	printf("Enter a character: ");
	c = getchar();

	int result = ft_tolower(c);

	if (result != c) {
		printf("The lowercase equivalent of '%c' is '%c'\n", c, result);
	} else {
		printf("'%c' is not an uppercase letter.\n", c);
	}

	return (0);
}*/
