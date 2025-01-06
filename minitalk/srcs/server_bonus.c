/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:15:36 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/01 12:09:47 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler_server(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		bit;
	static pid_t	pid_client;

	(void) context;
	if (info->si_pid != 0)
		pid_client = info->si_pid;
	if (signal == SIGUSR1)
		c |= (0b10000000 >> bit);
	else if (signal == SIGUSR2)
		c &= ~(0b10000000 >> bit);
	bit++;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (c == OVER)
		{
			write(1, "\n", 1);
			kill(pid_client, SIGUSR2);
			return ;
		}
		write(1, &c, 1);
	}
	kill(pid_client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_server;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Bonus Server's PID is: %i\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
}
