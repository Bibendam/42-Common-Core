/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:09:33 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:51:41 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		n *= -1;
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
/*
int	main(void) {
	int numbers[] = {-123, 0, 456, -2147483648, 999};
	size_t num_numbers = sizeof(numbers) / sizeof(numbers[0]);

	for (size_t i = 0; i < num_numbers; i++) {
		int n = numbers[i];
		char *str = ft_itoa(n);
		printf("Number: %d, String: %s\n", n, str);
		free(str); // Don't forget to free the allocated memory
	}

	return (0);
}*/
