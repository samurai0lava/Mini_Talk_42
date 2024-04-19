#include "mini_talk.h"

void signal_handler(int sig)
{
    printf("Signal received: %d\n", sig);
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    sa.sa_handler = &signal_handler;
    sigaction(SIGTSTP, &sa, NULL);

    while (1)
    {
        printf("Hello, world!\n");
        sleep(1);
    }

}

