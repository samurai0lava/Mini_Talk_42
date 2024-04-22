#include "mini_talk.h"

static void handler(int sig)
{
	write(1, "hello\n", 6);
}

static void handler1(int sig)
{
	write(1, "hello1\n", 6);
}
int ft_isdigit_adv(char *argv)
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
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sigaction(SIGINT, &sa, NULL);
	if(argc == 3 && ft_isdigit_adv(argv[1]) == 1)
	{
		pid = ft_atoi(argv[1]);
		
		
	}

}