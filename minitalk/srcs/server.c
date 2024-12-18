/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:15:36 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/18 21:36:00 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	recieve_signal(int signal) //recieve SIGUSR1 or SIGUSR2
{
	static unsigned char	current_char;
	static int				bit_index;
	
	if (signal == SIGUSR1)
		current_char = current_char | 1; //make it became XXXX XXX1 if signal = 1
	// else
	// 	current_char = current_char | 0;
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == OVER)
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char = current_char << 1; //move to have 1 more position XXXX XXX(this)
}

int	main(void)
{	
	ft_printf("PID server is: %i\n", getpid());
	signal(SIGUSR1, recieve_signal);
	signal(SIGUSR2, recieve_signal);
	while (1)
		pause(); // waiting for signal
	// return (EXIT_SUCCESS);
}