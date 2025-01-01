/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:29 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/31 18:05:27 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

volatile sig_atomic_t flag_server = BUSY; //to indicate when signal SIGUSR1 has been recived
// data type sig_atomic_t guarantee the flow of signal
// volatile qualifier forces the compiler to read the value of g from memory 

void	ack_handler(void)
{
	flag_server = READY; //ready to recieve next bit
}

void	end_handler(void)
{
	ft_printf("Message is recived by Server!");
	exit(EXIT_SUCCESS);
}

void	send_char(pid_t pid_server, char c)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		//Bitwise operations
		if (c & (0b10000000 >> bit)) // check value of that bit if it's 1, send 1
			ft_kill(pid_server, SIGUSR1);
		else //send 0
			ft_kill(pid_server, SIGUSR2);
		bit++;	//faire attention
		// stop, busy waiting
		while (flag_server == BUSY)
			usleep(42);
		// refresh global flag to BUSY to wait signal changes the ack_handler to READY
		flag_server = BUSY;
	}
}

/* ./client_bonus PID_server_bonus "message" */
int	main(int argc, char **argv)
{
	pid_t	pid_server;
	char	*message;
	
	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> \"Message\"\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid_server = ft_atoi(argv[1]);
	message = argv[2];

	ft_signal(SIGUSR1, ack_handler, false); //after server said already recived bit
	ft_signal(SIGUSR2, end_handler, false); //after server said already received whole message

	
	while (*message)
		send_char(pid_server, *message++);
	send_char(pid_server, OVER);
	
	return (EXIT_SUCCESS);
}
