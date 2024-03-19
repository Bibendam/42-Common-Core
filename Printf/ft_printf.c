/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:42:46 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/14 12:20:12 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formatted(const char format, va_list args)
{
	int	value;

	value = 0;
	if (format == 'c')
		value += ft_printchar(va_arg(args, int));
	else if (format == 's')
		value += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		value += ft_print_ptr((unsigned long long)va_arg(args, void *));
	else if (format == 'd')
		value += ft_printnbr(va_arg(args, int));
	else if (format == 'i')
		value += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		value += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		value += ft_print_hex(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		value += ft_print_hex(va_arg(args, unsigned int), 'X');
	else if (format == '%')
		value += ft_printpercent();
	return (value);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		value;
	int		i;

	i = 0;
	value = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			value += ft_formatted(str[i + 1], args);
			i++;
		}
		else
			value += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (value);
}
