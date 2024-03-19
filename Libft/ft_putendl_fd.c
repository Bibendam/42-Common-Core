/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:34:37 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:57:39 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *c, int fd)
{
	size_t	i;

	if (!c)
	{
		return ;
	}
	i = 0;
	while (c[i])
		i++;
	write(fd, c, i);
	write(fd, "\n", 1);
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

	// Write a string to the file using ft_putendl_fd
	ft_putendl_fd("Hello, world!", fd);

	close(fd); // Close the file

	printf("String written to output.txt\n");

	return (0);
}*/
