/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:12:48 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:51:13 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int num)
{
	if (num >= 0 && num <= 127)
		return (1);
	return (0);
}
/*
int	main(void) {
	int input[] = {65, 128, 97, '*', -1};
	size_t num_inputs = sizeof(input) / sizeof(input[0]);

	for (size_t i = 0; i < num_inputs; i++) {
		int num = input[i];
		if (ft_isascii(num)) {
			printf("%d is an ASCII character.\n", num);
		} else {
			printf("%d is not an ASCII character.\n", num);
		}
	}

	return (0);
}*/
