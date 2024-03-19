/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:01:37 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 12:01:14 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int num)
{
	if (num >= 'a' && num <= 'z')
		return (num -= 32);
	return (num);
}
/*
int	main(void) {
	int c;

	printf("Enter a character: ");
	c = getchar();

	int result = ft_toupper(c);

	if (result != c) {
		printf("The uppercase equivalent of '%c' is '%c'\n", c, result);
	} else {
		printf("'%c' is not a lowercase letter.\n", c);
	}

	return (0);
}*/
