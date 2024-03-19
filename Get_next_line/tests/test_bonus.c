/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:37:17 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/19 16:37:43 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	char *line;

	if (fd1 == -1 || fd2 == -1)
	{
		printf("Error opening files\n");
		return (1);
	}

	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("File1: %s\n", line);
		free(line);
	}

	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("File2: %s\n", line);
		free(line);
	}

	close(fd1);
	close(fd2);

	return (0);
}
