#include "mini_talk.h"

static void send_message(pid_t pid, int message)
{
	kill(pid, SIGUSR1 | message);
}

static int char_to_bin(char *str)
{
	int i;

	i = 0;
	/*
		convert string to binary to send it with siguser1
		using bitwise operations
	*/
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
	int					i;
	int message;
	// struct sigaction	sa;
	// sa.sa_handler = &handler;
	// sigaction(SIGINT, &sa, NULL);
	if(argc == 2 && ft_isdigit_adv(argv[1]) == 1)
	{
		message = char_to_bin(argv[2]);
		pid = ft_atoi(argv[1]);
		while(1)
		{
			send_message(pid, message);
			sleep(1); //wait the server to process the message sent
		}
	}

}