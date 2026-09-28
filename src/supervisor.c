#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

pid_t service_pid = -1;

volatile sig_atomic_t supervisor_running = 1;
volatile sig_atomic_t child_exited = 0;

void handle_sigchld(int sig)
{
    (void)sig;
    child_exited = 1;
}

void handle_sigint(int sig)
{
    (void)sig;
    supervisor_running = 0;
}

void start_service()
{
    if (service_pid > 0)
    {
        printf("[Supervisor] Service is already running. PID: %d\n",
               service_pid);
        return;
    }

    service_pid = fork();

    if (service_pid < 0)
    {
        perror("[Supervisor] fork failed");
        service_pid = -1;
        return;
    }

    if (service_pid == 0)
    {
        int log_fd = open("logs/test_service.log",
                          O_WRONLY | O_CREAT | O_APPEND,
                          0644);

        if (log_fd == -1)
        {
            perror("[Service Child] Cannot open log file");
            exit(EXIT_FAILURE);
        }

        dup2(log_fd, STDOUT_FILENO);
        dup2(log_fd, STDERR_FILENO);

        close(log_fd);

        execl("./services/test_service",
              "test_service",
              (char *)NULL);

        perror("[Service Child] exec failed");
        exit(EXIT_FAILURE);
    }

    printf("[Supervisor] Service started successfully.\n");
    printf("[Supervisor] Service PID: %d\n", service_pid);
}

void check_child_status()
{
    if (!child_exited || service_pid <= 0)
        return;

    int status;

    pid_t result = waitpid(service_pid, &status, WNOHANG);

    if (result == service_pid)
    {
        if (WIFEXITED(status))
        {
            printf("\n[Supervisor] Service exited with status %d.\n",
                   WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("\n[Supervisor] Service terminated by signal %d.\n",
                   WTERMSIG(status));
        }

        service_pid = -1;
        child_exited = 0;
    }
}

void stop_service()
{
    if (service_pid <= 0)
    {
        printf("[Supervisor] Service is not running.\n");
        return;
    }

    printf("[Supervisor] Sending SIGTERM to PID %d...\n",
           service_pid);

    if (kill(service_pid, SIGTERM) == -1)
    {
        perror("[Supervisor] kill failed");
        return;
    }

    int status;

    if (waitpid(service_pid, &status, 0) == -1)
    {
        perror("[Supervisor] waitpid failed");
    }
    else
    {
        printf("[Supervisor] Service terminated successfully.\n");
    }

    service_pid = -1;
    child_exited = 0;
}

void status_service()
{
    check_child_status();

    if (service_pid <= 0)
    {
        printf("[Supervisor] Service Status: STOPPED\n");
        return;
    }

    if (kill(service_pid, 0) == 0)
    {
        printf("[Supervisor] Service Status: RUNNING\n");
        printf("[Supervisor] Service PID: %d\n", service_pid);
    }
    else
    {
        printf("[Supervisor] Service Status: NOT RUNNING\n");
        service_pid = -1;
    }
}

void restart_service()
{
    printf("[Supervisor] Restarting service...\n");

    if (service_pid > 0)
    {
        stop_service();
        sleep(1);
    }

    start_service();
}

int main()
{
    int choice;

    struct sigaction sa_chld;
    struct sigaction sa_int;

    sa_chld.sa_handler = handle_sigchld;
    sigemptyset(&sa_chld.sa_mask);
    sa_chld.sa_flags = 0;

    sigaction(SIGCHLD, &sa_chld, NULL);

    sa_int.sa_handler = handle_sigint;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sigaction(SIGINT, &sa_int, NULL);

    printf("\n========================================\n");
    printf("     LINUX SERVICE PROCESS SUPERVISOR\n");
    printf("========================================\n");

    while (supervisor_running)
    {
        check_child_status();

        printf("\n");
        printf("1. Start Service\n");
        printf("2. Stop Service\n");
        printf("3. Service Status\n");
        printf("4. Restart Service\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        fflush(stdout);

        if (scanf("%d", &choice) != 1)
        {
            clearerr(stdin);

            while (getchar() != '\n')
                ;

            continue;
        }

        switch (choice)
        {
            case 1:
                start_service();
                break;

            case 2:
                stop_service();
                break;

            case 3:
                status_service();
                break;

            case 4:
                restart_service();
                break;

            case 5:
                supervisor_running = 0;
                break;

            default:
                printf("[Supervisor] Invalid choice.\n");
        }
    }

    printf("\n[Supervisor] Shutting down...\n");

    if (service_pid > 0)
    {
        stop_service();
    }

    printf("[Supervisor] Supervisor terminated safely.\n");

    return 0;
}
