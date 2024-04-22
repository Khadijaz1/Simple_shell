#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 on success
 */
int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            if (feof(stdin))
            {
                printf("\n");
                return (0);
            }
            perror("fgets");
            return (EXIT_FAILURE);
        }

        // Remove the newline character
        command[strlen(command) - 1] = '\0';

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("fork");
            return (EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // Child process
            execlp(command, command, (char *)NULL);
            // If execlp returns, an error occurred
            perror(command);
            return (EXIT_FAILURE);
        }
        else
        {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return (0);
}

