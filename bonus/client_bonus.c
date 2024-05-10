/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:52:07 by iouhssei          #+#    #+#             */
/*   Updated: 2024/05/10 14:03:35 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk_bonus.h"

int	g_message_received = 0;

static int	ft_isdigit_adv(char *argv)
{
	int	i;

	if (argv == NULL)
		return (0);
	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("The message has been received.\n");
		g_message_received = 1;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*message;
	int					i;
	int					check;
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3 && ft_isdigit_adv(argv[1]) == 1)
	{
		i = 0;
		message = argv[2];
		pid = ft_atoi(argv[1]);
		check = kill(pid, 0);
		if (check == -1)
			error_exit("Error: Invalid Pid");
		sending_msg_str(pid, message);
		while (g_message_received == 0)
		{
			pause();
		}
	}
	else
		error_exit("Usage: ./client [server_pid] [message]");
	return (0);
}
