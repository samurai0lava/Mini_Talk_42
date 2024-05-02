/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:42:56 by iouhssei          #+#    #+#             */
/*   Updated: 2024/05/02 12:16:07 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handler(int sigsent)
{
    static unsigned char	buff;
    static int				i;
    static pid_t			client_pid;
    static int				client_pid_received;

	client_pid_received = 0;
    buff |= (sigsent == SIGUSR1);
    i++;
    if (i == 8)
    {
        if (!client_pid_received)
        {
            client_pid = buff;
            client_pid_received = 1;
        }
        else if (buff == '\0')
        {
            kill(client_pid, SIGUSR1);
            client_pid_received = 0; // Ready to receive the PID of the next client
        }
        else
        {
            ft_printf("%c", buff);
        }
        i = 0;
        buff = 0;
    }
    else
    {
        buff <<= 1;
    }
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	(void)argv;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
    sa.sa_flags = SIGINFO;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("%d\n", pid);
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
	}
}
