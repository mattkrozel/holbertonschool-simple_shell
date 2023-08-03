#include "main.h"

void execute_input(char **argv)
{
	char *command = NULL, *real_command = NULL;
	
	if (argv)
	{
		command = argv[0];
		real_command = find_command(command);
		
		pid_t pid;
		int status;

		pid = fork();
		if (pid == 0)
		{
			execve(real_command, argv, NULL);
		}
		else
		{
			waitpid(pid, &status, 0);

		}
	}
}
