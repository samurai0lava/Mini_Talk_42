#include "../inc/mini_talk.h"

int message_received = 0;

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
}

static void send_end_of_message(pid_t pid)
{
    sending_msg(pid, '\0');
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

void handler(int sig)
{
    if (sig == SIGUSR1)
    {
        ft_printf("The message has been received.\n");
        message_received = 1;
    }
}

int main(int argc, char **argv)
{
    pid_t pid;
    char *message;
    int i;
    int check;
    struct sigaction sa;


    sa.sa_handler = handler;
    sigaction(SIGUSR1, &sa, NULL);
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
                ft_printf("Invalid pid\n");
                return 1;
            }
            i++;
        }
        send_end_of_message(pid);
        while (message_received == 0)
        {
            pause();
        }
    }
    else
    {
        ft_printf("Usage: ./client [server_pid] [message]\n");
        return (1);
    }
    return (0);
}