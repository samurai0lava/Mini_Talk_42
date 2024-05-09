#include "../inc/mini_talk.h"

void	error_exit(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}