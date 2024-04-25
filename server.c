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

int main(int argc, char **argv)
{
	pid_t pid;
	(void)argv;
	if(argc == 1)
	{
		pid = getpid();
		ft_printf("%d\n", pid);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		while(1)
		{
			pause(); //wait for the client to send a message
		}
	}
	else
	{
		ft_printf("Usage: ./server\n");
	}
}