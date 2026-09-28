#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void monitor_process(pid_t pid) {
    char path[100];
    char line[256];
    FILE *file;

    snprintf(path, sizeof(path), "/proc/%d/status", pid);

    file = fopen(path, "r");

    if (file == NULL) {
        perror("[Monitor] Unable to open process information");
        return;
    }

    printf("\n========================================\n");
    printf("       PROCESS MEMORY MONITOR\n");
    printf("========================================\n");
    printf("PID: %d\n\n", pid);

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0 ||
            strncmp(line, "State:", 6) == 0 ||
            strncmp(line, "Pid:", 4) == 0 ||
            strncmp(line, "PPid:", 5) == 0 ||
            strncmp(line, "VmSize:", 7) == 0 ||
            strncmp(line, "VmRSS:", 6) == 0) {

            printf("%s", line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    if (pid <= 0) {
        printf("Invalid PID.\n");
        return 1;
    }

    monitor_process(pid);

    return 0;
}
