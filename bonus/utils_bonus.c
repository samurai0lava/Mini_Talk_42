#include "../inc/mini_talk.h"

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
		usleep(500);
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
