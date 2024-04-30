/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:42:56 by iouhssei          #+#    #+#             */
/*   Updated: 2024/04/30 14:06:16 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handler(int sigsent)
{
	static unsigned char	buff;
	static int				i;

	buff |= (sigsent == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", buff);
		i = 0;
		buff = 0;
	}
	else
		buff <<= 1;
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	(void)argv;
	struct sigaction	sa;

	sa.sa_handler = handler;	
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
