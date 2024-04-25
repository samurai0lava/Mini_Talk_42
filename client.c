#include "mini_talk.h"

static void	sending_msg(pid_t pid, unsigned char octet)
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
		usleep(100);
	}
}


static int ft_isdigit_adv(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 1)
			i++;
		else
			return (0);
	}
	return(1);
}


int main(int argc, char **argv)
{
	pid_t				pid;
	char				*message;
	int i;


	if(argc == 3 && ft_isdigit_adv(argv[1]) == 1)
	{
		i = 0;
		message = argv[2];
		pid = ft_atoi(argv[1]);
		while(message[i])
		{
			sending_msg(pid, message[i]);
			i++;
		}
	}
	else
	{
		ft_printf("Usage: ./client [server_pid] [message]\n");
	}
}