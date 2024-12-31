/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:56:49 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/31 18:17:34 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

//using sigaction provide better control, includeing signal masking and flags
// system requires that handler has these 3 parameters (even context is unused)
// handler for these signals, if recived SIGUSR1 -> bit 1, SIGUSR2 -> bit 0
void    handler(int signal, siginfo_t *info, void *context)
{
    (void)      context; // mark that context is unused
    static char c; //0 by default - to recived and transform bits to char
    static int  bit; //0 by default - only for count from 0 to 8

    static pid_t pid_client; // to send back that whole message recived
    
    if (info->si_pid != 0) //because si_pid return itself to 0 after few calls
        pid_client = info->si_pid;
    if (signal == SIGUSR1)
        c |= (0b10000000 >> bit); //set that bit to 1
    else if (signal == SIGUSR2)
        c &= ~(0b10000000 >> bit); // set that bit to 0
    bit++;
    //once recived the char:
    // 1) print char
    // 2) tell sender to send another
    if (bit == CHAR_BIT)
    {
        bit = 0;
        if (c == OVER) //the last of message
        {
            write(1, "\n", 1);
            // Message recived: send SIGUSR2 back to sender to inform! not in bonus
            ft_kill(pid_client, SIGUSR2);
            return;
        }
        write(1, &c, 1);
    }
    //to tell ready to recive the next bit: send sigusr1
    ft_kill(pid_client, SIGUSR1);
    
}

int main(void)
{
    ft_printf("Server(bonus) PID is: %i\n", getpid()); //return int
    ft_signal(SIGUSR1, handler, true);
    ft_signal(SIGUSR2, handler, true);

    while (42)
        pause(); //wait forever

}
