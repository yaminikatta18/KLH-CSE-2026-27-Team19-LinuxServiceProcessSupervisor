#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t running = 1;

void handle_signal(int sig)
{
    if (sig == SIGTERM || sig == SIGINT)
    {
        printf("\n[Test Service] Shutdown signal received.\n");
        running = 0;
    }
}

int main()
{
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    printf("[Test Service] Started\n");
    printf("[Test Service] PID  : %d\n", getpid());
    printf("[Test Service] PPID : %d\n", getppid());

    while (running)
    {
        printf("[Test Service] Running... PID = %d\n", getpid());
        sleep(5);
    }

    printf("[Test Service] Terminated safely.\n");

    return 0;
}
