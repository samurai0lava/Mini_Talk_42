/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:07:40 by iouhssei          #+#    #+#             */
/*   Updated: 2024/05/09 21:08:40 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk_bonus.h"

void	sending_msg(pid_t pid, unsigned char octet)
{
	int				i;
	unsigned char	octet_tmp;

	octet_tmp = octet;
	i = 8;
	while (i-- > 0)
	{
		octet_tmp = octet >> i;
		if (octet_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(400);
	}
}

void	send_end_of_message(pid_t pid)
{
	sending_msg(pid, '\0');
}

void	sending_msg_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		sending_msg(pid, str[i]);
		i++;
	}
	send_end_of_message(pid);
}

void	error_exit(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}
