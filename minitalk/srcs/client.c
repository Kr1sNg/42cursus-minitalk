/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:15:26 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/18 21:34:17 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SIGUSR1 send 1 and SIGUSR2 send 0
#include "../includes/minitalk.h"
//#include <stdio.h>
//#include <string.h>

void	send_signal(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	tmp = c;
	while (i > 0)
	{
		i--;
		tmp = c >> i; // '0010 1010' when i = 3 is '0000 0101'
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2); // send SIG2 then reciever will read it like (0) 0000 0000
		else
			kill(pid, SIGUSR1); //send SIG1 then reciever will read it like (1) 0000 0001
		usleep(42);
	}
}

int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	const char	*message;
	int			i;

	if (argc != 3)
	{
		ft_printf("Usage: %s 'PID' 'message'\n", argv[0]);
		exit(EXIT_SUCCESS);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_signal(server_pid, message[i]);
		i++;
	}
	send_signal(server_pid, OVER);
	return (EXIT_SUCCESS);
}