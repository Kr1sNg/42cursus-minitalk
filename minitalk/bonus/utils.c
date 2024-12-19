/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:33:47 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/19 17:33:51 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void    Signal(int signo, void *handler, bool use_siginfo)
{
    struct sigaction    sa = {0};

    // put the handler func inside struct sigaction (see man)
    if (use_siginfo)
    {
        sa.sa_flags = SA_SIGINFO;   //function with more data
        sa.sa_sigaction = handler;
    }
    else
        sa.sa_handler = handler;    // don't need more data

    //block SIGURS1 while processing SIGUSR2 and viceversa
    sigemptyset(&sa.sa_mask);   // to block
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);

    // call sigaction check for mistake
    if (sigaction(signo, &sa, NULL) < 0)
    {
        ft_printf("Sigaction failed");
        exit(EXIT_FAILURE);
    }

}

