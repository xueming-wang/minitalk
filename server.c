#include <signal.h>
#include <unistd.h>
#include <libc.h>

void ft_handle(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Received SIGUSR1!\n");
    }
    else if (sig == SIGUSR2)
    {
        printf("Received SIGUSR2!\n");
    }
}

int main()
{
    pid_t pid;

    pid = getpid();
    printf("%d\n", pid);

    if (signal(SIGUSR1, ft_handle) == SIG_ERR)
    {
        perror("Can't set handler for SIGUSR1");
        // exit(1);
    }
    if (signal(SIGUSR2, ft_handle) == SIG_ERR)
    {
        perror("Can't set handler for SIGUSR2");
        // exit(1);
    }

    while(1);

    pause();
}

// A -> ascci : 65
// 65 -> 1 BYTES -> 8 bits
// 65 : 0100 0001
//
// loop :
//
//  -> client 1 -> server 1
//  -> client 0 -> server 0
//  -> client 0 -> server 0
//  -> client 0 -> server 0
//  -> client 0 -> server 0
//  -> client 0 -> server 0
//  -> client 1 -> server 1
//  -> client 0 -> server 0
