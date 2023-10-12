#include "shell.h"

/**
 * main - entry point
 *
 * Return: Always 0
 */

int main(int ac, char **argv)
{
	while (1)
	{
		printf("SimpleShell>>");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;

		}

		command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();

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
