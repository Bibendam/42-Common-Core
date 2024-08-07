/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:09:17 by drizzo            #+#    #+#             */
/*   Updated: 2024/04/18 15:16:33 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_digits(const char *str, int *num)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (*num > INT_MAX / 10 || (*num == INT_MAX / 10 && str[i]
				- '0' > INT_MAX % 10))
		{
			return (0);
		}
		*num = *num * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

static const char	*skip_non_digits(const char *str)
{
	if (str == NULL)
	{
		return (NULL);
	}
	while (*str != '\0' && (*str >= '\t' && *str <= '\r'))
	{
		str++;
	}
	return (str);
}

static const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	return (str);
}

static const char	*get_sign(const char *str, int *sign)
{
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	overflow;
	int	num;

	sign = 1;
	num = 0;
	str = skip_non_digits(str);
	if (str == NULL || *str == '\0')
		return (0);
	str = skip_whitespace(str);
	if (str == NULL || *str == '\0')
		return (0);
	str = get_sign(str, &sign);
	overflow = convert_digits(str, &num);
	if (!overflow)
	{
		if (sign == 1)
			return (INT_MAX);
		return (INT_MIN);
	}
	return (num * sign);
}
/*
int	main(void) {
	const char *str = "   -12345abc";
	int result = ft_atoi(str);
	printf("Converted string \"%s\" to integer: %d\n", str, result);
	return (0);
}*/
