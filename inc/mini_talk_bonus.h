#ifndef MINI_TALK_H
# define MINI_TALK_H

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
