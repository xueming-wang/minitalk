#include <signal.h>
#include <unistd.h>
#include <libc.h>

int main(int ac, char **av)
{
    if (ac != 3)
        return (1);
    int pid = atoi(av[1]);
    int kill_ret = kill(pid, SIGUSR1);
    if (kill_ret == -1)
    {
        printf("usr1 failed\n");
        kill_ret = kill(pid, SIGUSR2);
        if (kill_ret == -1)
        {
            printf("usr2 failed\n");
        }
    }
    return (0)
}
