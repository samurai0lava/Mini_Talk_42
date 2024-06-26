/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:59:37 by iouhssei          #+#    #+#             */
/*   Updated: 2024/05/10 13:59:39 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_talk.h"

void	error_exit(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}
