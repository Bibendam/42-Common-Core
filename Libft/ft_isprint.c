/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:30:08 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:51:20 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int num)
{
	if (num >= 32 && num <= 126)
		return (1);
	return (0);
}
/*
int	main(void) {
	int test_chars[] = {'A', 'Z', 'a', 'z', '0', '9', '$', '!', '\t'};
	int result;

	printf("Testing ft_isprint function:\n");

	for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
		result = ft_isprint(test_chars[i]);
		if (result)
			printf("'%c': Printable\n", test_chars[i]);
		else
			printf("'%c': Not printable\n", test_chars[i]);
	}

	return (0);
}*/
