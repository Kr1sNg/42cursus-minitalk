/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:49 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/19 16:56:52 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void    handler(int signo, siginfo_t *info, void *more_info)
{
    (void)more_info;
    write(STDOUT_FILENO, "hello\n", 6);
}


int main(void)
{
    ft_printf("Server(bonus) PID is: %i\n", getpid()); //return int
    Signal(SIGUSR1, handler, true);
    Signal(SIGUSR2, handler, true);

    while (42)
        pause(); //wait forever

}
