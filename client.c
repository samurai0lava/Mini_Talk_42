#include "mini_talk.h"

int main(int argc, char **argv)
{
	pid_t pid;

	if(argc == 1)
	{
		while(1)
		{
			pid = getpid();
			ft_printf("%d\n", pid);
		}
	}
	return(0);
}
