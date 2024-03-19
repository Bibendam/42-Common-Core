/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:36:40 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:51:09 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int num)
{
	return ((num >= 'a' && num <= 'z') || (num >= 'A' && num <= 'Z'));
}
/*
int	main(void) {
	int input[] = {'a', '5', '*', ' ', 'Z', 123, -1};
	size_t num_inputs = sizeof(input) / sizeof(input[0]);

	for (size_t i = 0; i < num_inputs; i++) {
		int num = input[i];
		if (ft_isalpha(num)) {
			printf("%c (%d) is alphabetic.\n", num, num);
		} else {
			printf("%c (%d) is not alphabetic.\n", num, num);
		}
	}

	return (0);
}*/
