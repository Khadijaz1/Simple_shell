#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("$ ");
        fflush(stdout);

        // Read the command
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            printf("\n");
            break;
        }

        // Remove the newline character
        command[strlen(command) - 1] = '\0';

        // Fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            // Fork failed
            perror("fork");
        } else if (pid == 0) {
            // Child process
            execlp(command, command, (char *)NULL);
            // If execlp returns, an error occurred
            perror("exec");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

