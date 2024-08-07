/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:09:31 by drizzo            #+#    #+#             */
/*   Updated: 2024/08/07 15:17:43 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	confirm_message(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received by server\n");
	else
		ft_printf("Error: message not received by server\n");
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			signal(SIGUSR1, confirm_message);
			signal(SIGUSR2, confirm_message);
			send_char(pid, argv[2][i]);
			i++;
		}
		send_char(pid, '\n');
	}
	else
	{
		printf("Error: wrong number of arguments\n");
		printf("Try: ./client <PID> <message>\n");
		return (1);
	}
	return (0);
}
