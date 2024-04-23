#include "mini_talk.h"

static bin_to_char(int binary)
{
	int i;
	i = 0;
	/*
		convert binary to string after recieved it from the client  do i need a function to check if recieved or not
		using bitwise operations
	*/
}
int main(int argc, char **argv)
{
	pid_t pid;

	struct sigaction sa;
	if(argc == 1)
	{
		pid = getpid();
		ft_printf("%d\n", pid);
		while(1)
		{
			pause();
		}
	}
	return(0);
}