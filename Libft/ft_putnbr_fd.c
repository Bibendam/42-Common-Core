/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:36:15 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:57:45 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nb(long nb, int fd)
{
	if (nb >= 10)
	{
		print_nb(nb / 10, fd);
	}
	ft_putchar_fd((char)(nb % 10 + '0'), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	print_nb(nb, fd);
}
/*
int	main(void)
{
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	// Test positive number
	ft_putnbr_fd(123, fd);
	ft_putchar_fd('\n', fd);

	// Test negative number
	ft_putnbr_fd(-456, fd);
	ft_putchar_fd('\n', fd);

	close(fd); // Close the file

	printf("Numbers written to output.txt\n");

	return (0);
}*/
