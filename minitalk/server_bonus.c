/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:09:27 by drizzo            #+#    #+#             */
/*   Updated: 2024/08/22 14:59:40 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_sig1(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == '\n')
		{
			ft_printf("\n");
			if (info != NULL)
			{
				kill(info->si_pid, SIGUSR1);
			}
		}
		else
		{
			ft_printf("%c", i);
		}
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

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
	sig.sa_sigaction = handle_sig1;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
