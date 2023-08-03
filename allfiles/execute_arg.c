#include "main.h"

void execute_input(char **argv)
{
	char *command = NULL, *real_command = NULL;
	pid_t pid;
	int status;

	if (argv)
	{
		command = argv[0];
		real_command = find_command(command);
		

		pid = fork();
		if (pid == 0)
		{
			execve(real_command, argv, NULL);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (status != 0)
			{
				fprintf(stderr, "Command failed with status %d. \n", status);
			}

		}
	}
}
