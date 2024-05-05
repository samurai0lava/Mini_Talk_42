#include "../inc/mini_talk.h"

void handler(int sigsent, siginfo_t *info, void *context)
{
    static unsigned char buff = 0;
    static int i = 0;
    static pid_t client_pid = 0;
    static int client_pid_received = 0;

    (void)context;
    (void)info;
    if (!client_pid_received) {
        client_pid = info->si_pid;
        client_pid_received = 1;
    }

    buff |= (sigsent == SIGUSR1);
    i++;

    if (i == 8)
    {
        if (buff == '\0')
        {
            kill(client_pid, SIGUSR1);
            client_pid_received = 0;
            usleep(500);
        }
        else
        {
            ft_printf("%c", buff);
        }
        i = 0;
        buff = 0;
    }
    else
    {
        buff <<= 1;
    }
}


int main(int argc, char **argv)
{
    (void)argv;
    struct sigaction sa;

    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;

    if (argc == 1)
    {
        pid_t pid = getpid();
        ft_printf("Server PID: %d\n", pid);
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        while (1)
        {
            pause();
        }
    }
    else
    {
        ft_printf("Usage: ./server\n");
        return (1);
    }

    return (0);
}
