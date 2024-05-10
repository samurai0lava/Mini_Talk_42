/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:08:56 by iouhssei          #+#    #+#             */
/*   Updated: 2024/05/10 14:03:24 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk_bonus.h"

void	handler(int sigsent, siginfo_t *info, void *context)
{
	static int				client_pid_received;
	static unsigned char	buff;
	static int				i;

	(void)context;
	(void)info;
	if (!client_pid_received)
		client_pid_received = 1;
	buff |= (sigsent == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (buff == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			client_pid_received = 0;
			usleep(500);
		}
		else
			ft_printf("%c", buff);
		i = 0;
		buff = 0;
	}
	else
		buff <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	(void)argv;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (argc == 1)
	{
		pid = getpid();
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
