/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:05:05 by iouhssei          #+#    #+#             */
/*   Updated: 2024/05/10 14:07:00 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_BONUS_H
# define MINI_TALK_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "../libft/libft.h"

void	error_exit(char *error_message);
void	sending_msg(pid_t pid, unsigned char octet);
void	send_end_of_message(pid_t pid);
void	sending_msg_str(pid_t pid, char *str);

#endif
