#include "shell.h"

#define MAX_COMMAND_LENGTH 256

/**
 * main - entry point
 * @ac: number of argument passed
 * @argv: arguments passed
 * Return: Always 0
 */

int main(int ac, char **argv)
{
	pid_t pid;
	char command[MAX_COMMAND_LENGTH];

	(void)ac;

	while (1)
	{
		printf("SimpleShell>>");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;

		}

		command[strcspn(command, "\n")] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
			return (1);
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
