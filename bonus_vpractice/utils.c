/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:33:47 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/31 16:13:34 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

//set up Signal SIGURS1 and SIGUSR2
void    ft_signal(int signo, void *handler, bool siginfo_is_needed)
{
    struct sigaction    sa = {0};

    // put the handler func inside struct sigaction (see man)
    if (siginfo_is_needed)
    {
        sa.sa_flags = SA_SIGINFO;   //function with more data
        sa.sa_sigaction = handler;
    }
    else
        sa.sa_handler = handler;    // don't need more data

    //block SIGURS1 while processing SIGUSR2 and viceversa
    sigemptyset(&sa.sa_mask);   // to block
    // sigaddset(&sa.sa_mask, SIGUSR1);
    // sigaddset(&sa.sa_mask, SIGUSR2);

    // call sigaction check for mistake
    if (sigaction(signo, &sa, NULL) < 0)
    {
        ft_printf("Sigaction failed");
        exit(EXIT_FAILURE);
    }

}

void    ft_kill(pid_t pid, int signo)
{
    if (kill(pid, signo) < 0)
    {
        ft_printf("Kill failed\n");
        exit(EXIT_FAILURE);
    }
}

