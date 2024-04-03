/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:33:43 by drizzo            #+#    #+#             */
/*   Updated: 2024/04/03 13:47:28 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *str = "Hello, world!";
    int num = 12345;
    void *ptr = (void *)0x12345678;
	ft_printf("Testing the ft_printf function:\n");
	ft_printf("Printing a string: %s\n", str);
	ft_printf("Printing a decimal number: %d\n", num);
	ft_printf("Printing a pointer: %p\n", ptr);
	ft_printf("Printing in hexadecimal: %x\n", num);
	ft_printf("Printing in hexadecimal (uppercase): %X\n", num);
	ft_printf("Printing a percentage sign: %%\n");
	ft_printf("Printing a single character: %c\n", 'A');
    ft_printf("Printing a negative decimal number: %d\n", -num);
    ft_printf("Printing a null pointer: %p\n", NULL);
    ft_printf("Printing zero in hexadecimal: %x\n", 0);
    ft_printf("Printing zero in uppercase hexadecimal: %X\n", 0);
    ft_printf("Printing zero: %d\n", 0);
    ft_printf("Printing a very large number: %d\n", 2147483647);
    ft_printf("Printing a very large negative number: %d\n", -2147483647);
	return (0);
}
//compile with "cc ft_printf.c ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c ft_print_utils.c libftprintf.a test.c"
