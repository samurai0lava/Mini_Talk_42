#include "mini_talk.h"

static int	sending_msg(pid_t pid, unsigned char octet)
{
	int				i;
	unsigned char	octet_tmp;
	int				check;

	octet_tmp = octet;
	i = 8;
	while (i-- > 0)
	{
		octet_tmp = octet >> i;
		if (octet_tmp % 2 == 0)
			check = kill(pid, SIGUSR2);
		else
			check = kill(pid, SIGUSR1);
		usleep(300);
	}
	return (check);
	//send '\0' wich is 8 bits "0000 0000" to said to the server that u finihed the message and u send back a signal to the client to tell him that u have recieved the whole messag
}

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

int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*message;
	int					i;
	int					check;

	if (argc == 3 && ft_isdigit_adv(argv[1]) == 1)
	{
		i = 0;
		message = argv[2];
		pid = ft_atoi(argv[1]);
		while (message[i])
		{
			check = sending_msg(pid, message[i]);
			if (check == -1)
			{
				ft_printf ("Invalid pid\n");
			}
			i++;
		}
	}
	else
	{
		ft_printf("Usage: ./client [server_pid] [message]\n");
	}
}
