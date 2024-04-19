#include "mini_talk.h"

void sig_handler(int sig)
{
    printf("\nallo %d\n", sig);
}
int main(int argc, char **argv)
{
    signal(SIGINT, SIG_ERR);
    while(1)
        sleep(1);
    return (0);
}

