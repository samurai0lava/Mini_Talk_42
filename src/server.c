/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:42:56 by iouhssei          #+#    #+#             */
/*   Updated: 2024/05/03 13:20:20 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk.h"

void handler(int sigsent)
{
    static unsigned char    buff;
    static int              i;
    
    buff = 0;
    i = 0;
    buff |= (sigsent == SIGUSR1);
    i++;
    if (i == 8)
    {
        ft_printf("%c", buff);

    }
    else
    {
        buff <<= 1;
    }
}

int main(int argc, char **argv)
{
    (void)argv;
    struct sigaction sa;

    sa.sa_handler = handler;
    if (argc == 1)
    {
        pid_t pid = getpid();
        ft_printf("Server PID: %d\n", pid);
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        while (1)
        {
            pause();
        }
    }
    else
    {
        ft_printf("Usage: ./server\n");
        return (1);
    }

    return (0);
}
