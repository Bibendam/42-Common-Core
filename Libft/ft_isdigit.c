/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:56:26 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:51:16 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int digit)
{
	if (digit >= 48 && digit <= 57)
		return (1);
	return (0);
}
/*
int	main(void) {
	int test_chars[] = {'A', 'Z', 'a', 'z', '0', '9', '$', '!', '\0'};
	int result;

	printf("Testing ft_isdigit function:\n");

	for (int i = 0; test_chars[i]; i++) {
		result = ft_isdigit(test_chars[i]);
		if (result)
			printf("'%c': Digit\n", test_chars[i]);
		else
			printf("'%c': Not a digit\n", test_chars[i]);
	}

	return (0);
}*/
