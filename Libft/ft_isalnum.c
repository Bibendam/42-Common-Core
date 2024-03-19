/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:01:55 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:51:01 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int num)
{
	return (ft_isalpha(num) || ft_isdigit(num));
}
/*
int	main(void) {
	int input[] = {'a', '5', '*', ' ', 'Z', 123, -1};
	size_t num_inputs = sizeof(input) / sizeof(input[0]);

	for (size_t i = 0; i < num_inputs; i++) {
		int num = input[i];
		if (ft_isalnum(num)) {
			printf("%c (%d) is alphanumeric.\n", num, num);
		} else {
			printf("%c (%d) is not alphanumeric.\n", num, num);
		}
	}

	return (0);
}*/
