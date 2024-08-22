/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:47:49 by drizzo            #+#    #+#             */
/*   Updated: 2024/08/22 13:40:20 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig1(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong number of arguments\n");
		ft_printf("Try: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Waiting for message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, handle_sig1);
		signal(SIGUSR2, handle_sig1);
		pause();
	}
	return (0);
}
